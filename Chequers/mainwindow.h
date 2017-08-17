#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "player.h"
#include "loginform.h"
#include "game.h"
#include <QTableWidgetItem>

class CLoginForm;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void SetLoginForm(CLoginForm* form);

public slots:
    void onLogin(bool result);

    void onGetPlayersListResponse(QList<CPlayer> availablePlayers);

    void onStartNewGameServerResponse(int result);

    void onNewGameRequested(std::string hostPlayerName);

    void onNewGameRequestPlayerResponse(int response);

    void onGameInitialization(char playerColor);

    void onBoardReceived(char* board);

    void onGameEnded(std::string result, std::string reason);

    void onLogout();

    void onYourMove(bool);

    void onGameStateChanged(CGame::E_GameState newState);

    void onRedrawRequest();

    void onMoveAccepted();

    void onMoveNotAccepted();

private slots:
    void on_tW_availablePlayers_doubleClicked(const QModelIndex &index);

    void on_pB_logout_pressed();

    void on_pB_resign_pressed();

    void on_pB_requestNewGame_pressed();

    void on_tW_board_itemClicked(QTableWidgetItem *item);

    void onMoveTimerTimeout();

    void onRefreshPlayersTimeout();

private:

    void m_startNewGame(std::string userName);

    void m_initializeLayout();

    void m_initializeBoard();

    Ui::MainWindow *ui;

    CLoginForm* m_loginForm;

    int m_xSelected, m_ySelected;

    bool m_isPawnSelected = false;

    QTimer* m_pGameTimer;

    int m_gameTime;

    QTimer* m_pRefreshPlayersTimer;

    const int m_refreshPlayersTimeMs = 1000;
};

#endif // MAINWINDOW_H
