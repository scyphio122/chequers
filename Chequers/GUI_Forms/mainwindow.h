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

/**
 * @brief The MainWindow class - Class managing the main window of the application
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**
     * @brief SetLoginForm - Setter for the login form. Needed to show after loggin out
     * @param form - pointer to the login form
     */
    void SetLoginForm(CLoginForm* form);

public slots:
    /**
     * @brief onLogin - Callback for login action
     * @param result - true if login successful, false otherwise
     */
    void onLogin(bool result);

    /**
     * @brief onGetPlayersListResponse - Callback for getting players list - it shows the list on the @var ui->tW_availablePlayers
     * @param availablePlayers - [in] list with available players
     */
    void onGetPlayersListResponse(QList<CPlayer> availablePlayers);

    /**
     * @brief onStartNewGameServerResponse - Callback for server response for starting new game request
     * @param result true if request passed successfully, false otherwise
     */
    void onStartNewGameServerResponse(int result);

    /**
     * @brief onNewGameRequested - Callback for invitation for new game. Used to display pop-up with request.
     * @param hostPlayerName - username of player who invites the user
     */
    void onNewGameRequested(std::string hostPlayerName);

    /**
     * @brief onNewGameRequestPlayerResponse - Callback for response for our game invitation
     * @param response [in]- true if game is to be started, false if opponent declined
     */
    void onNewGameRequestPlayerResponse(int response);

    /**
     * @brief onGameInitialization - Callback for server's game initialization
     * @param playerColor [in]- Color which is assigned ot user.
     */
    void onGameInitialization(char playerColor);

    /**
     * @brief onBoardReceived - Callback for receiving the board layout from server
     * @param board [in]- char[8][8] with pawns location
     */
    void onBoardReceived(char* board);

    /**
     * @brief onGameEnded - Callback for end of the game
     * @param result [in]- username of the player who won
     * @param reason [in]- reason for game end
     */
    void onGameEnded(std::string result, std::string reason);

    /**
     * @brief onLogout - Callback for logging out
     */
    void onLogout();

    /**
     * @brief onYourMove - Callback for 'YMV' server command
     */
    void onYourMove(bool);

    /**
     * @brief onGameStateChanged - Callback for game state change
     * @param newState - new state to set
     */
    void onGameStateChanged(CGame::E_GameState newState);

    /**
     * @brief onRedrawRequest - Callback for redrawing the board request
     */
    void onRedrawRequest();

    /**
     * @brief onMoveAccepted - Callback for server's accepting the move request
     */
    void onMoveAccepted();

    /**
     * @brief onMoveNotAccepted - Callback for server's declining the move request
     */
    void onMoveNotAccepted();

private slots:
    /**
     * @brief on_tW_availablePlayers_doubleClicked - Callback for handling the double click on the user on the player's list.
     * @param index [in]- index of player on the list
     */
    void on_tW_availablePlayers_doubleClicked(const QModelIndex &index);

    /**
     * @brief on_pB_logout_pressed - Callback for pressing the 'Logout' button
     */
    void on_pB_logout_pressed();

    /**
     * @brief on_pB_resign_pressed - Callback for pressing the 'Resign' button
     */
    void on_pB_resign_pressed();

    /**
     * @brief on_pB_requestNewGame_pressed - Callback for pressing the 'Start new game' button
     */
    void on_pB_requestNewGame_pressed();

    /**
     * @brief on_tW_board_itemClicked - Callback for clicking the board cell
     * @param item [in]- item clicked
     */
    void on_tW_board_itemClicked(QTableWidgetItem *item);

    /**
     * @brief onMoveTimerTimeout - Callback for move timer - causes the timer to increase
     */
    void onMoveTimerTimeout();

    /**
     * @brief onRefreshPlayersTimeout - Callback for refresh players list timer
     */
    void onRefreshPlayersTimeout();

private:
    /**
     * @brief m_checkIfPlayerListMatch - Function for checking if the new players list has changed from the current one
     * @param newList [in]- new players list
     * @return true if current list and new list are the same. False if they are different
     */
    bool m_checkIfPlayerListMatch(QList<CPlayer> &newList);

    /**
     * @brief m_startNewGame - Function for requesting another player to start new game
     * @param userName - username of the player to be invited
     */
    void m_startNewGame(std::string userName);

    /**
     * @brief m_initializeLayout - Function for initializing the layout of the whole window
     */
    void m_initializeLayout();

    /**
     * @brief m_initializeBoard - Function for initializing the board layout
     */
    void m_initializeBoard();

    /**
     * @brief ui - pointer to the window graphic low level manager
     */
    Ui::MainWindow *ui;

    /**
     * @brief m_loginForm - Pointer to the login form
     */
    CLoginForm* m_loginForm;

    /**
     * @brief m_xSelected - index of the x coordinate of the selected pawn
     */
    int m_xSelected;

    /**
     * @brief m_ySelected- index of the y coordinate of the selected pawn
     */
    int m_ySelected;

    /**
     * @brief m_isPawnSelected
     */
    bool m_isPawnSelected = false;

    /**
     * @brief m_pGameTimer - Pointer to the timer which ticks every second during the play
     */
    QTimer* m_pGameTimer;

    /**
     * @brief m_gameTime - holds time in seconds since game started
     */
    int m_gameTime;

    /**
     * @brief m_pRefreshPlayersTimer - pointer to the timer which cyclically refreshes the user timers
     */
    QTimer* m_pRefreshPlayersTimer;

    /**
     * @brief m_refreshPlayersTimeMs - time in milliseconds between two ticks of refresh players timer
     */
    const int m_refreshPlayersTimeMs = 1000;

    /**
     * @brief m_availablePlayersTableWidgetRowCounter - holds the index of the last added row in the players list widget
     */
    int m_availablePlayersTableWidgetRowCounter;
};

#endif // MAINWINDOW_H
