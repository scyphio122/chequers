#ifndef CGAME_H
#define CGAME_H

#include <QObject>
#include <QMutex>
#include "webprotocolframe.h"
#include "protocolframeparser.h"
#include <QTimer>

/**
 * @brief The CGame class - This is SINGLETON class which controls the whole 'Game Application'.
 *        It provides high level API to communicate with game server.
 */
class CGame : public QObject
{
    Q_OBJECT
public:

    /// @enum E_SideColor - enum for pawns color
    enum class E_SideColor : char
    {
        E_INVALID,
        E_WHITE = 'B',
        E_BLACK = 'C'
    };

    /// @enum E_GameState - enum for
    enum class E_GameState : unsigned char
    {
        /** Logged out **/
        E_NOT_INITIALIZED,

        /** Logged in - no pending game invitations */
        E_LOGGED_IN,

        /** Waiting for the other player to accept the game invitation */
        E_WAITING_FOR_ACCEPT,

        /** The game request has been received. Waiting till the user responds to invitatioln. */
        E_GAME_REQUEST,

        /** Game has been started */
        E_PLAYING_GAME
    };

    ~CGame();

    /**
     * @brief GetInstance - Get the instance of game controlling object
     * @return game controlling object
     */
    static CGame* GetInstance();

    /**
     * @brief GetBoard - Get the last pawns layout on board, received from the server.
     * @return char[8][8] - array describing pawns layout on the board
     */
    char* GetBoard();

    /**
     * @brief GetSideColor - It returns the color of side which the user has received from server
     * @return  E_BLACK or E_WHITE
     */
    E_SideColor GetSideColor();

    /**
     * @brief GetQueenCharacter - Get the character which describes the queen pawn of the user
     *         on the board
     * @return 'D' - for E_WHITE, 'E' for E_BLACK
     */
    char GetQueenCharacter();

    /**
     * @brief GetUserName - Get the username of the currently logged in user
     * @return username
     */
    std::string GetUserName();

    /**
     * @brief IsMyTurn -
     * @return true if user's turn, false if opponent is to make his move
     */
    bool IsMyTurn();

    /* GAME API */

    /**
     * @brief Login - Function to log in to the server
     * @param username
     * @param password
     * @return true if succeeded, false if failed (user already logged, no user existing, etc.)
     */
    bool Login(std::string username, std::string password);

    /**
     * @brief RegisterUser - Function to register new user on the server
     * @param username
     * @param password
     * @return true if succeeded, false if failed (user already existing, etc.)
     */
    bool RegisterUser(std::string username, std::string password);

    /**
     * @brief GetPlayersList - Send request to the server to send the currently logged in players list
     * @return true if succeded, false if request sending failure
     */
    bool GetPlayersList();

    /**
     * @brief StartNewGame - Function which sends request to the server, to ask a @param secondPlayerName
     *                       if he wants to start a new game with us
     * @param secondPlayerName - username of the other player
     * @return true if succeded, false if request sending failure
     */
    bool StartNewGame(std::string secondPlayerName);

    /**
     * @brief RespondToGameInvitation - Respond to the received game invitation
     * @param accept - true if invitation accepted, false otherwise
     * @return true if succeded, false if request sending failure
     */
    bool RespondToGameInvitation(bool accept);

    /**
     * @brief MakeMove - Make a move
     * @param xFrom - x of the chosen pawn
     * @param yFrom - y of the chosen pawn
     * @param xTo - x where the chosen pawn should land
     * @param yTo - y where the chosen pawn should land
     * @return true if succeded, false if request sending failure
     */
    bool MakeMove(int xFrom, int yFrom, int xTo, int yTo);

    /**
     * @brief Logout - Logout from the server
     * @return true if succeded, false if request sending failure
     */
    bool Logout();

    /**
     * @brief Resign - Resign from the currently played game
     * @return true if succeded, false if request sending failure
     */
    bool Resign();

signals:
    /**
     * @brief signalStateChanged - Signal emitted each time the game state is changed
     * @param newState - state which is changed to
     */
    void signalStateChanged(CGame::E_GameState newState);

    /**
     * @brief signalRedrawBoard - signal emitted to force redrawing the board layout on the GUI
     */
    void signalRedrawBoard();

    /**
     * @brief signalLogout - signal emitted when the @fn Logout function is called
     */
    void signalLogout();

    /**
     * @brief signalMoveMade - signal emitted when the server accepts the move request
     */
    void signalMoveMade();

    /**
     * @brief signalMoveDiscarded - signal emitted when the server declines the move request
     */
    void signalMoveDiscarded();

    /**
     * @brief signalStartPlayerListRefreshTimer - signal emitted to start again the timer which
     *       cyclically polls the server to obtain list of currently logged in players
     */
    void signalStartPlayerListRefreshTimer();

    /**
     * @brief signalStopPlayerListRefreshTimer - signal emitted to stop the timer which
     *       cyclically polls the server to obtain list of currently logged in players
     */
    void signalStopPlayerListRefreshTimer();

public slots:
    /**
     * @brief onLoginResponse - Callback for login server response
     * @param response - true if login succeeded, false otherwise
     */
    void onLoginResponse(bool response);

    /**
     * @brief onUserRegistrationResponse - Callback for user registration server response
     * @param response - true if succeded, false otherwise
     */
    void onUserRegistrationResponse(bool response);

    /**
     * @brief onGetPlayersListResponse - Callback for user playersList request.
     * @param playersList - provided by the server list of players
     */
    void onGetPlayersListResponse(QList<CPlayer> playersList);

    /**
     * @brief onStartNewGameServerResponse - Callback for StartNewGame server response
     * @param result - request passed successfully to another player, false otherwise
     */
    void onStartNewGameServerResponse(int result);

    /**
     * @brief onNewGameRequested - Callback for receiving new game invitations from another players
     * @param hostPlayerName - username of the player who invited us
     */
    void onNewGameRequested(std::string hostPlayerName);

    /**
     * @brief onNewGameRequestPlayerResponse - Callback for new game request response from player
     * @param response - 1 if player accepted our invitation, 0 otherwise
     */
    void onNewGameRequestPlayerResponse(int response);

    /**
     * @brief onGameInitialization - Callback for server's game initialization
     * @param playerColor - 'B' if player is to use @enum E_GameSide::E_WHITE, 'C' if @enum E_GameSide::E_BLACK
     */
    void onGameInitialization(char playerColor);

    /**
     * @brief onBoardReceived - Callback for receiving board layout from server
     * @param board - char[8][8]
     */
    void onBoardReceived(char* board);

    /**
     * @brief onYourMove - Callback from server which notifies about user's turn
     * @param status - ignored
     */
    void onYourMove(bool status);

    /**
     * @brief onGameEnded - Callback for servicing End of Game
     * @param result - winning username
     * @param reason - reason of the game end
     */
    void onGameEnded(std::string result, std::string reason);

    /**
     * @brief onMakeMoveServerResponse - Callback for users MakeMove.
     * @param result - 1 if server accepted the move, 0 - if declined
     */
    void onMakeMoveServerResponse(int result);

private:

    CGame();

    /**
     * @brief m_SendFrame - Function which sends the frame via @class CWebManager
     * @param frame - frame to send
     * @return true if send succeeded, false otherwise
     */
    bool m_SendFrame(CWebProtocolFrame& frame);

    /**
     * @brief m_changeState - makes the state of the game change
     * @param newState - state to be changed to
     * @return true if succeeded, false otherwise
     */
    bool m_changeState(E_GameState newState);

    /**
     * @brief m_state - Current state of the game
     */
    E_GameState m_state;

    /**
     * @brief s_stateMap - map holding mapping from E_GameState to human readable name of state
     */
    static std::map<E_GameState, const char*> s_stateMap;

    /**
     * @brief m_userColor - Color assigned by the server
     */
    E_SideColor m_userColor;

    /**
     * @brief m_userKingColor - Character describing user's queen
     */
    char m_queenCharacter;

    /**
     * @brief m_playersList - Last received logged in users list
     */
    QList<CPlayer> m_playersList;

    /**
     * @brief m_loggedIn - true if logged in the server, false otherwise
     */
    bool m_loggedIn;

    /**
     * @brief m_isMyTurn - true if user's turn, false otherwise
     */
    bool m_isMyTurn;

    /**
     * @brief m_userName - username of the logged in user. Empty if not logged in
     */
    std::string m_userName;

    /**
     * @brief m_pParser - Pointer to the Frame received from the server parsing object
     */
    CProtocolFrameParser* m_pParser;

    /**
     * @brief m_board - array holding last received from the server board layout
     */
    char m_board[8][8];

    /**
     * @brief m_bufferedBoard - array holding the proposition of board layout while making a move
     */
    char m_bufferedBoard[8][8];

    /**
     * @brief m_pThread - Pointer to the thread in which the object is running
     */
    QThread* m_pThread;

    /**
     * @brief m_pMutex - Pointer to the mutex
     */
    QMutex* m_pMutex;

};

#endif // CGAME_H
