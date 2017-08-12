#ifndef WEBPROTOCOLFRAME_H
#define WEBPROTOCOLFRAME_H

#include <QByteArray>
#include <map>

class CWebProtocolFrame
{
public:

    enum class E_ServerCommands : char
    {
        E_UNDEFINED = -1,
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
        E_GAME_ENDED = 11,
        E_LOGOUT = 12,
        E_ERROR = 13,
        E_INCONSISTENCY = 14
    };

    CWebProtocolFrame();

    void FormFrame(std::string commandString, std::string params);

    void FormFrameFromReceivedData(std::string rawData);

    QByteArray GetCommand();

    QList<QByteArray> GetParameters();

    QByteArray& GetFrame();

    char* GetRawFrame();

    unsigned int GetFrameSize();

    static std::string GetCommandFromMap(E_ServerCommands cmd);

    static E_ServerCommands GetCommandFromMap(std::string cmd);

    static std::map<E_ServerCommands, std::string>s_commandsMap;

private:
    void m_setCommand(std::string &commandString);

    void m_setParameters(std::string& params);

    QByteArray m_frame;
};

#endif // WEBPROTOCOLFRAME_H
