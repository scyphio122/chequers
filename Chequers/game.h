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

    /* GAME API */

    bool Login(std::string username, std::string password);

    bool RegisterUser(std::string username, std::string password);

    bool GetPlayersList();

    bool StartNewGame(std::string secondPlayerName);

    bool MakeMove();

    bool Logout();

    bool Resign();

signals:
    void signalStateChanged(E_GameState newState);

    void signalRedrawBoard();

public slots:
    void onLoginResponse(bool response);

    void onUserRegistrationResponse(bool response);

    void onGetPlayersListResponse(QList<CPlayer> playersList);

    void onStartNewGameServerResponse(int result);

    void onNewGameRequested(std::string hostPlayerName);

    void onNewGameRequestPlayerResponse(int response);

    void onGameInitialization(char playerColor);

    void onBoardReceived(char board[8][8]);

    void onYourMove(bool status);

    void onGameEnded(std::string result, std::string reason);

private:

    CGame();

    bool m_SendFrame(CWebProtocolFrame& frame);

    bool m_changeState(E_GameState newState);

    E_GameState m_state;

    static std::map<E_GameState, const char*> s_stateMap;

    E_SideColor m_userColor;

    QList<CPlayer> m_playersList;

    bool m_loggedIn;

    CProtocolFrameParser* m_pParser;

    char m_board[8][8];

    QThread* m_pThread;

    QMutex* m_pMutex;
};

#endif // CGAME_H
