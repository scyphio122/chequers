#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include "protocolframeparser.h"
#include "game.h"
#include <QMessageBox>
#include "logger.h"
#include "gamerequestpopup.h"
#include <QColor>
#include <map>
#include <QImage>


#define DARK_FIELD_COLOR    QColor::fromRgb(112, 82, 0)
#define LIGHT_FIELD_COLOR   QColor::fromRgb(252, 233, 164)
#define WHITE_PAWN          'B'
#define DARK_PAWN           'C'
#define WHITE_QUEEN         'D'
#define DARK_QUEEN          'E'
#define EMPTY_FIELD         'O'

#define SIZE_OFFSET         5

static std::map<char, QImage*> s_pawnImagesMap;

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

    QImage* whitePawn = new QImage(QImage("white_pawn_transparent.png").scaled(ui->tW_board->columnWidth(0) - SIZE_OFFSET, ui->tW_board->rowHeight(0) - SIZE_OFFSET));
    QImage* darkPawn = new QImage(QImage("dark_pawn_transparent.png").scaled(ui->tW_board->columnWidth(0) - SIZE_OFFSET, ui->tW_board->rowHeight(0) - SIZE_OFFSET));
    QImage* whiteQueen = new QImage(QImage("white_pawn_transparent_queen.png").scaled(ui->tW_board->columnWidth(0) - SIZE_OFFSET, ui->tW_board->rowHeight(0) - SIZE_OFFSET));
    QImage* darkQueen = new QImage(QImage("dark_pawn_transparent_queen.png").scaled(ui->tW_board->columnWidth(0) - SIZE_OFFSET, ui->tW_board->rowHeight(0) - SIZE_OFFSET));

    s_pawnImagesMap.insert(std::pair<char, QImage*>(WHITE_PAWN, whitePawn));
    s_pawnImagesMap.insert(std::pair<char, QImage*>(DARK_PAWN, darkPawn));
    s_pawnImagesMap.insert(std::pair<char, QImage*>(WHITE_QUEEN, whiteQueen));
    s_pawnImagesMap.insert(std::pair<char, QImage*>(DARK_QUEEN, darkQueen));

    m_initializeLayout();

    connect(CGame::GetInstance(), SIGNAL(signalStateChanged(CGame::E_GameState)), this, SLOT(onGameStateChanged(CGame::E_GameState)));

    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalLoginRetval(bool)), this, SLOT(onLogin(bool)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalListOfPlayersReceived(QList<CPlayer>)), this, SLOT(onGetPlayersListResponse(QList<CPlayer>)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalNewGameRequestPassed(int)), this, SLOT(onStartNewGameServerResponse(int)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalNewGameRequestResponse(int)), this, SLOT(onNewGameRequestPlayerResponse(int)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalNewGameRequested(std::string)), this, SLOT(onNewGameRequested(std::string)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalGameInitialization(char)), this, SLOT(onGameInitialization(char)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalBoardReceived(char*)), this, SLOT(onBoardReceived(char*)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalGameEnded(std::string,std::string)), this, SLOT(onGameEnded(std::string,std::string)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalYourMove(bool)), this, SLOT(onYourMove(bool)));

    connect(CGame::GetInstance(), SIGNAL(signalRedrawBoard()), this, SLOT(onRedrawRequest()));
    connect(CGame::GetInstance(), SIGNAL(signalLogout()), this, SLOT(onLogout()));
    connect(CGame::GetInstance(), SIGNAL(signalMoveMade()), this, SLOT(onMoveAccepted()));
    connect(CGame::GetInstance(), SIGNAL(signalMoveDiscarded()), this, SLOT(onMoveNotAccepted()));

    m_pGameTimer = new QTimer();
    m_pGameTimer->setInterval(1000);
    m_pGameTimer->setSingleShot(false);
    connect(m_pGameTimer, SIGNAL(timeout()), this, SLOT(onMoveTimerTimeout()));

    m_pRefreshPlayersTimer = new QTimer();
    m_pRefreshPlayersTimer->setInterval(m_refreshPlayersTimeMs);
    m_pRefreshPlayersTimer->setSingleShot(false);
    connect(m_pRefreshPlayersTimer, SIGNAL(timeout()), this, SLOT(onRefreshPlayersTimeout()));
}

MainWindow::~MainWindow()
{
    ui->tW_availablePlayers->clear();
    delete s_pawnImagesMap[WHITE_PAWN];
    delete s_pawnImagesMap[DARK_PAWN];
    delete s_pawnImagesMap[WHITE_QUEEN];
    delete s_pawnImagesMap[DARK_QUEEN];

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
    ui->lcd_time->display("0:00");

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
                item->setData(Qt::DecorationRole, QString(""));
                item->setText("");
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
                item->setData(Qt::DecorationRole, QString(""));
                item->setText("");
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
void MainWindow::onLogin(bool result)
{
    if (result)
        m_pRefreshPlayersTimer->start();
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
    QString text;
    QString turnText;
    m_pRefreshPlayersTimer->stop();
    if (playerColor == (char)CGame::E_SideColor::E_BLACK)
    {
        text = "BLACK";
        turnText = "OPPONENT's MOVE!";
    }
    else
    {
        text = "WHITE";
        turnText = "YOUR MOVE!";
    }

    ui->gB_board->setEnabled(true);
    ui->gB_AvailablePlayers->setEnabled(false);
    ui->lE_yourColor->setText(text);
    ui->lE_whoseTurn->setText(turnText);
    m_gameTime = 0;
    m_pGameTimer->start();
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
                case WHITE_PAWN:
                {
                    tw->item(row, col)->setData(Qt::DecorationRole, *s_pawnImagesMap[WHITE_PAWN]);
                    tw->item(row, col)->setText(QString(WHITE_PAWN));
//                    tw->item(row,col)->da
                }break;
                case DARK_PAWN:
                {
                    tw->item(row, col)->setData(Qt::DecorationRole, *s_pawnImagesMap[DARK_PAWN]);
                    tw->item(row, col)->setText(QString(DARK_PAWN));
                }break;
                case WHITE_QUEEN:
                {
                    tw->item(row, col)->setData(Qt::DecorationRole, *s_pawnImagesMap[WHITE_QUEEN]);
                    tw->item(row, col)->setText(QString(WHITE_QUEEN));
                }break;
                case DARK_QUEEN:
                {
                    tw->item(row, col)->setData(Qt::DecorationRole, *s_pawnImagesMap[DARK_QUEEN]);
                    tw->item(row, col)->setText(QString(DARK_QUEEN));
                }break;
                case EMPTY_FIELD:
                {
                    tw->item(row, col)->setData(Qt::DecorationRole, " ");
                    tw->item(row, col)->setText(" ");
                }break;
            }
        }
    }
}

void MainWindow::onGameEnded(std::__cxx11::string result, std::__cxx11::string reason)
{
    QMessageBox box;

    ui->gB_AvailablePlayers->setEnabled(true);
    m_pGameTimer->stop();
    m_pRefreshPlayersTimer->start();

    box.setText("Player " + QString::fromStdString(result) + " won. Reason is: " + QString::fromStdString(reason));
    box.setIcon(QMessageBox::NoIcon);
    box.exec();

    ui->lcd_time->display("0:00");
    m_initializeBoard();
}

void MainWindow::onLogout()
{
    m_initializeLayout();
    this->hide();
    m_loginForm->show();
}

void MainWindow::onYourMove(bool)
{
    LOG_DBG(" ");
    ui->lE_whoseTurn->setText("YOUR MOVE!");
}

void MainWindow::onMoveAccepted()
{
    LOG_DBG(" ");
    ui->lE_whoseTurn->setText("OPPONENT's MOVE!");
    ui->tW_board->item(m_ySelected, m_xSelected)->setSelected(false);
    m_isPawnSelected = false;
    m_xSelected = -1;
    m_ySelected = -1;
}

void MainWindow::onMoveNotAccepted()
{
    QMessageBox box;
    box.setText("The move you're trying to make is not acceptable. Try again!");
    box.setIcon(QMessageBox::Warning);
    box.exec();
}

void MainWindow::m_startNewGame(std::__cxx11::string userName)
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    CGame::GetInstance()->StartNewGame(userName);
}

void MainWindow::onMoveTimerTimeout()
{
    m_gameTime++;
    int minutes = m_gameTime / 60;
    int seconds = m_gameTime % 60;
    QString text;
    if (seconds >= 10)
        text = QString::number(minutes) + ":" + QString::number(seconds);
    else
        text = QString::number(minutes) + ":0" + QString::number(seconds);

    ui->lcd_time->display(text);
}

void MainWindow::onRefreshPlayersTimeout()
{
    CGame::GetInstance()->GetPlayersList();
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
    // Do not allow to do anything while opponent's turn
    if (!CGame::GetInstance()->IsMyTurn())
        return;

    // Select the place to move the pawn
    if (m_isPawnSelected)
    {
        if (item->text()[0] != (char)CGame::GetInstance()->GetSide() &&
            item->text()[0] != CGame::GetInstance()->GetKingColor())
        {
            CGame::GetInstance()->MakeMove(m_xSelected, m_ySelected, item->column(), item->row());
        }
    }

    // Select/unselect pawn to move
    if (item->text()[0] == (char)CGame::GetInstance()->GetSide() ||
        item->text()[0] == CGame::GetInstance()->GetKingColor() ||
        item->text()[0] == EMPTY_FIELD)
    {
        if (item->text()[0] == EMPTY_FIELD)
            return;

        if (!m_isPawnSelected)
        {
            item->setSelected(true);
            m_isPawnSelected = true;
            m_xSelected = item->column();
            m_ySelected = item->row();
        }
        else
        {
            if (item->row() == m_ySelected && item->column() == m_xSelected)
            {
                item->setSelected(false);
                m_isPawnSelected = false;
            }
        }
        return;
    }
}
