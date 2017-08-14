#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "player.h"
#include "loginform.h"
#include "game.h"

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
    void onGetPlayersListResponse(QList<CPlayer> availablePlayers);

    void onStartNewGameServerResponse(int result);

    void onNewGameRequested(std::string hostPlayerName);

    void onNewGameRequestPlayerResponse(int response);

    void onGameInitialization(char playerColor);

    void onBoardReceived(char* board);

    void onGameEnded(std::string result, std::string reason);

    void onLogout();

    void onGameStateChanged(CGame::E_GameState newState);

private slots:
    void on_tW_availablePlayers_doubleClicked(const QModelIndex &index);

    void on_pB_logout_pressed();

    void on_pB_resign_pressed();

    void on_pB_requestNewGame_pressed();

private:

    void m_startNewGame(std::string userName);

    void m_initializeLayout();

    Ui::MainWindow *ui;

    CLoginForm* m_loginForm;
};

#endif // MAINWINDOW_H
