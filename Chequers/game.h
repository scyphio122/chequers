#ifndef CGAME_H
#define CGAME_H

#include <QObject>
#include <map>
#include <QMutex>

class CGame : public QObject
{
    Q_OBJECT
public:
    ~CGame();

    static CGame* GetInstance();

    bool Login(std::string username, std::string password);

    bool RegisterUser(std::string username, std::string password);

    bool MakeMove();
signals:

public slots:

private:

    enum class E_GameState : unsigned char
    {
        E_NOT_INITIALIZED,
    };

    enum class E_SideColor : char
    {
        E_INVALID,
        E_WHITE = 'B',
        E_BLACK = 'C'
    };

    enum class E_ServerCommands : unsigned char
    {
        E_LOGIN = 1,
        E_REGISTER_USER = 2,
        E_GET_PLAYERS_LIST = 3,
        E_START_NEW_GAME = 4,
        E_NEW_GAME_REQUESTED = 5,
        E_NEW_GAME_REQUEST_RESPONSE = 6,
        E_GAME_INITIALIZATION = 7,
        E_BOARD = 8,
        E_YOUR_MOVE = 9,
        E_RESIGN = 10,
        E_END_GAME = 11,
        E_LOGOUT = 12,
        E_ERROR = 13,
        E_INCONSISTENCY = 14
    };

    static std::map<E_ServerCommands, std::string>s_commandsMap;

    CGame();

    std::string m_getCommandString(CGame::E_ServerCommands command);

    E_GameState m_state;

    E_SideColor m_userColor;

    char m_board[8][8];

    QThread* m_pThread;

    QMutex* m_pMutex;
};

#endif // CGAME_H
