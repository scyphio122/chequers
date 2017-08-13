#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include "protocolframeparser.h"
#include "game.h"
#include <QMessageBox>
#include "logger.h"
#include "gamerequestpopup.h"

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

    connect(CGame::GetInstance(), SIGNAL(signalStateChanged(CGame::E_GameState)), this, SLOT(onGameStateChanged(CGame::E_GameState)));

    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalListOfPlayersReceived(QList<CPlayer>)), this, SLOT(onGetPlayersListResponse(QList<CPlayer>)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalNewGameRequestPassed(int)), this, SLOT(onStartNewGameServerResponse(int)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalNewGameRequestResponse(int)), this, SLOT(onNewGameRequestPlayerResponse(int)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalNewGameRequested(std::string)), this, SLOT(onNewGameRequested(std::string)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalGameInitialization(char)), this, SLOT(onGameInitialization(char)));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalBoardReceived(char[8][8])), this, SLOT(onBoardReceived(char[8][8])));
    connect(CProtocolFrameParser::GetInstance(), SIGNAL(signalGameEnded(std::string,std::string)), this, SLOT(onGameEnded(std::string,std::string)));

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
    ui->pB_logout->setEnabled(true);
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

        ui->gB_AvailablePlayers->setEnabled(true);
        // Refresh the players list
        CGame::GetInstance()->GetPlayersList();
    }
}

void MainWindow::onNewGameRequestPlayerResponse(int response)
{
    // Player has agreed to start the game
    if (response > 0)
    {
        ui->gB_AvailablePlayers->setEnabled(false);
    }
    else
    {
        ui->gB_AvailablePlayers->setEnabled(true);
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

}

void MainWindow::onBoardReceived(char board[8][8])
{

}

void MainWindow::onGameEnded(std::__cxx11::string result, std::__cxx11::string reason)
{
    QMessageBox box;

    box.setText("You " + QString::fromStdString(result) + ". Reason is: " + QString::fromStdString(reason));
    box.setIcon(QMessageBox::NoIcon);
    box.exec();

    ui->gB_AvailablePlayers->setEnabled(true);
}

void MainWindow::onLogout()
{
    m_initializeLayout();
    this->close();
    m_loginForm->show();
}


void MainWindow::m_startNewGame(std::__cxx11::string userName)
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->gB_AvailablePlayers->setEnabled(false);
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
