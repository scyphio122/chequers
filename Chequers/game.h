#ifndef CGAME_H
#define CGAME_H

#include <QObject>
#include <QMutex>
#include "webprotocolframe.h"
#include "protocolframeparser.h"


class CGame : public QObject
{
    Q_OBJECT
public:

    enum class E_SideColor : char
    {
        E_INVALID,
        E_WHITE = 'B',
        E_BLACK = 'C'
    };

    enum class E_GameState : unsigned char
    {
        E_NOT_INITIALIZED,

        /** zalogowany - brak oczekujących zaproszeń */
        E_LOGGED_IN,

        /** czeka na zaakceptowanie zaproszenia do gry */
        E_WAITING_FOR_ACCEPT,

        /** zaproszenie do gry (w trakcie odpowiadania na zaproszenie) */
        E_GAME_REQUEST,

        /** gra rozpoczęta */
        E_PLAYING_GAME
    };

    ~CGame();

    static CGame* GetInstance();

    char* GetBoard();

    E_SideColor GetSide();

    char GetKingColor();

    std::string GetUserName();

    bool IsMyTurn();

    /* GAME API */

    bool Login(std::string username, std::string password);

    bool RegisterUser(std::string username, std::string password);

    bool GetPlayersList();

    bool StartNewGame(std::string secondPlayerName);

    bool RespondToGameInvitation(bool accept);

    bool MakeMove(int xFrom, int yFrom, int xTo, int yTo);

    bool Logout();

    bool Resign();

signals:
    void signalStateChanged(CGame::E_GameState newState);

    void signalRedrawBoard();

    void signalLogout();

    void signalMoveMade();

    void signalMoveDiscarded();
public slots:
    void onLoginResponse(bool response);

    void onUserRegistrationResponse(bool response);

    void onGetPlayersListResponse(QList<CPlayer> playersList);

    void onStartNewGameServerResponse(int result);

    void onNewGameRequested(std::string hostPlayerName);

    void onNewGameRequestPlayerResponse(int response);

    void onGameInitialization(char playerColor);

    void onBoardReceived(char* board);

    void onYourMove(bool status);

    void onGameEnded(std::string result, std::string reason);

    void onMakeMoveServerResponse(int result);

private:

    CGame();

    bool m_SendFrame(CWebProtocolFrame& frame);

    bool m_changeState(E_GameState newState);

    E_GameState m_state;

    static std::map<E_GameState, const char*> s_stateMap;

    E_SideColor m_userColor;

    char m_userKingColor;

    QList<CPlayer> m_playersList;

    bool m_loggedIn;

    bool m_isMyTurn;

    std::string m_userName;

    CProtocolFrameParser* m_pParser;

    char m_board[8][8];

    char m_bufferedBoard[8][8];

    QThread* m_pThread;

    QMutex* m_pMutex;
};

#endif // CGAME_H
