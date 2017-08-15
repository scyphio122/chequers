#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include "protocolframeparser.h"
#include "game.h"
#include <QMessageBox>
#include "logger.h"
#include "gamerequestpopup.h"
#include <QColor>

#define DARK_FIELD_COLOR QColor::fromRgb(112, 82, 0)
#define LIGHT_FIELD_COLOR QColor::fromRgb(252, 233, 164)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Chequers Client");
    this->setWindowIconText("Chequers Client");
    ui->tW_availablePlayers->insertColumn(0);
    ui->tW_availablePlayers->insertColumn(1);
    ui->tW_availablePlayers->setHorizontalHeaderItem(0, new QTableWidgetItem("User name"));
    ui->tW_availablePlayers->setHorizontalHeaderItem(1, new QTableWidgetItem("Status"));

    m_initializeLayout();

    connect(CGame::GetInstance(), SIGNAL(signalStateChanged(CGame::E_GameState)), this, SLOT(onGameStateChanged(CGame::E_GameState)));

    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalListOfPlayersReceived(QList<CPlayer>)), this, SLOT(onGetPlayersListResponse(QList<CPlayer>)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalNewGameRequestPassed(int)), this, SLOT(onStartNewGameServerResponse(int)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalNewGameRequestResponse(int)), this, SLOT(onNewGameRequestPlayerResponse(int)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalNewGameRequested(std::string)), this, SLOT(onNewGameRequested(std::string)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalGameInitialization(char)), this, SLOT(onGameInitialization(char)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalBoardReceived(char*)), this, SLOT(onBoardReceived(char*)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalGameEnded(std::string,std::string)), this, SLOT(onGameEnded(std::string,std::string)));

    connect(CGame::GetInstance(), SIGNAL(signalRedrawBoard()), this, SLOT(onRedrawRequest()));
    connect(CGame::GetInstance(), SIGNAL(signalLogout()), this, SLOT(onLogout()));
}

MainWindow::~MainWindow()
{
    ui->tW_availablePlayers->clear();
    delete ui;
}

void MainWindow::SetLoginForm(CLoginForm *form)
{
    m_loginForm = form;
}

void MainWindow::m_initializeLayout()
{
    ui->tW_availablePlayers->setRowCount(0);
    ui->gB_AvailablePlayers->setEnabled(true);
    ui->gB_board->setEnabled(false);
    ui->pB_logout->setEnabled(true);

    m_initializeBoard();
}

void MainWindow::m_initializeBoard()
{
    QTableWidget* tw = ui->tW_board;

    for(int i = 0; i<tw->columnCount(); ++i)
    {
        for(int j = 0; j<tw->rowCount(); ++j)
        {
            if ((i+j) % 2 == 0)
            {
                QTableWidgetItem* item = tw->item(i, j);
                if (item == nullptr)
                {
                    item = new QTableWidgetItem();
                    tw->setItem(i, j, item);
                }

                item->setBackgroundColor(LIGHT_FIELD_COLOR);
            }
            else
            {
                QTableWidgetItem* item = tw->item(i, j);
                if (item == nullptr)
                {
                    item = new QTableWidgetItem();
                    tw->setItem(i, j, item);
                }

                item->setBackgroundColor(DARK_FIELD_COLOR);
            }
        }
    }
}

void MainWindow::onGameStateChanged(CGame::E_GameState newState)
{
    switch (newState)
    {
        case CGame::E_GameState::E_NOT_INITIALIZED:
        {
            ui->pB_logout->setEnabled(false);
        }break;

        case CGame::E_GameState::E_GAME_REQUEST:
        {
            ui->pB_logout->setEnabled(false);

        }break;

        case CGame::E_GameState::E_PLAYING_GAME:
        {
            ui->pB_logout->setEnabled(false);
        }
        default:
            break;
    }
}

void MainWindow::onGetPlayersListResponse(QList<CPlayer> availablePlayers)
{
    QTableWidget* tw = ui->tW_availablePlayers;
    QTableWidgetItem* userName;
    QTableWidgetItem* status;

    // Delete all the rows
    tw->setRowCount(0);

    int numOfPlayers = availablePlayers.size();
    for(int i=0; i<numOfPlayers; ++i)
    {
        // Ignore myself
        if (availablePlayers[i].GetPlayerName() == CGame::GetInstance()->GetUserName())
            continue;

        tw->insertRow(i);
        userName = new QTableWidgetItem(QString::fromStdString(availablePlayers[i].GetPlayerName()));
        status = new QTableWidgetItem(QString::fromStdString(availablePlayers[i].GetStatusString()));
        tw->setItem(i, 0, userName);
        tw->setItem(i, 1, status);
    }
}

void MainWindow::onStartNewGameServerResponse(int result)
{
    if (result > 0)
    {
        return;
    }
    else
    {
        QApplication::restoreOverrideCursor();

        QMessageBox box;
        box.setText("Could not send new game request - user is not available");
        box.setIcon(QMessageBox::Critical);
        box.exec();

        // Refresh the players list
        CGame::GetInstance()->GetPlayersList();
    }
}

void MainWindow::onNewGameRequestPlayerResponse(int response)
{
    QApplication::restoreOverrideCursor();
    // Player has agreed to start the game
    if (response > 0)
    {

    }
    else
    {

    }
}

void MainWindow::onNewGameRequested(std::__cxx11::string hostPlayerName)
{
    QString text = "User " + QString::fromStdString(hostPlayerName + " has requested new game. Do you want to accept the invitation?");
    CGameRequestPopup popup;
    popup.SetText(text);
    popup.exec();
}

void MainWindow::onGameInitialization(char playerColor)
{
    ui->gB_board->setEnabled(true);
    ui->gB_AvailablePlayers->setEnabled(false);
}

void MainWindow::onBoardReceived(char *board)
{

}

void MainWindow::onRedrawRequest()
{
    char board[8][8];
    memcpy((char*)board, CGame::GetInstance()->GetBoard(), 64);

    QTableWidget* tw = ui->tW_board;
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            switch (board[row][col])
            {
                case 'B':
                {
                    tw->item(row, col)->setText(QString(board[row][col]));
                }break;
                case 'C':
                {
                    tw->item(row, col)->setText(QString(board[row][col]));
                }break;
                case 'D':
                {
                    tw->item(row, col)->setText(QString(board[row][col]));
                }break;
                case 'E':
                {
                    tw->item(row, col)->setText(QString(board[row][col]));
                }break;
                case 'O':
                {
                    tw->item(row, col)->setText("");
                }break;
            }
        }
    }

}

void MainWindow::onGameEnded(std::__cxx11::string result, std::__cxx11::string reason)
{
    QMessageBox box;

    box.setText("Player " + QString::fromStdString(result) + " won. Reason is: " + QString::fromStdString(reason));
    box.setIcon(QMessageBox::NoIcon);
    box.exec();

    ui->gB_board->setEnabled(false);
    ui->gB_AvailablePlayers->setEnabled(true);
}

void MainWindow::onLogout()
{
    m_initializeLayout();
    this->hide();
    m_loginForm->show();
}


void MainWindow::m_startNewGame(std::__cxx11::string userName)
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    CGame::GetInstance()->StartNewGame(userName);
}


void MainWindow::on_tW_availablePlayers_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    std::string userName = ui->tW_availablePlayers->item(row, 0)->text().toStdString();
    m_startNewGame(userName);
}

void MainWindow::on_pB_logout_pressed()
{
    CGame::GetInstance()->Logout();
}

void MainWindow::on_pB_resign_pressed()
{
    CGame::GetInstance()->Resign();
}

void MainWindow::on_pB_requestNewGame_pressed()
{
    QList<QTableWidgetItem*> selectedItems = ui->tW_availablePlayers->selectedItems();
    if (selectedItems.empty())
    {
        QMessageBox box;
        box.setText("No player selected");
        box.setIcon(QMessageBox::Information);
        box.exec();
        return;
    }

    int row = selectedItems[0]->row();
    std::string userName = ui->tW_availablePlayers->item(row, 0)->text().toStdString();
    m_startNewGame(userName);
}

void MainWindow::on_tW_board_itemClicked(QTableWidgetItem *item)
{
    static bool isPawnSelected = false;
    static int xSelected, ySelected;

    // Select/unselect pawn to move
    if (item->text().toStdString()[0] == (char)CGame::GetInstance()->GetSide() ||
            item->text().toStdString()[0] == CGame::GetInstance()->GetKingColor())
    {
        if (!isPawnSelected)
        {
            item->setSelected(true);
            isPawnSelected = true;
            xSelected = item->column();
            ySelected = item->row();
        }
        else
        {
            if (item->row() == ySelected && item->column() == xSelected)
            {
                item->setSelected(false);
                isPawnSelected = false;
                xSelected = -1;
                ySelected = -1;
            }
        }
        return;
    }

    // Select the place to move the pawn
    if (isPawnSelected)
    {
        if (item->text().toStdString()[0] != (char)CGame::GetInstance()->GetSide() &&
            item->text().toStdString()[0] != CGame::GetInstance()->GetKingColor())
        {
            CGame::GetInstance()->MakeMove(xSelected, ySelected, item->column(), item->row());
        }
    }


}
