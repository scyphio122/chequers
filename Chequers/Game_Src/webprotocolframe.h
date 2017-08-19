#ifndef WEBPROTOCOLFRAME_H
#define WEBPROTOCOLFRAME_H

#include <QByteArray>
#include <map>

/**
 * @brief The CWebProtocolFrame class - Class wrapping around the chequers protocol packet
 */
class CWebProtocolFrame
{
public:
    /**
     * @brief The E_ServerCommands enum - Enum containgin the different packets type
     */
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
        E_INCONSISTENCY = 14,
        E_MAKE_MOVE = 15
    };

    CWebProtocolFrame();

    /**
     * @brief FormFrame - Function for forming packets. Used to form packets from the one received from the server
     * @param commandString - command string
     * @param params - params string
     */
    void FormFrame(std::string commandString, std::string params = std::string());

    /**
     * @brief FormFrame - Function for forming packets. Used to form packets to be sent to server
     * @param command - command type
     * @param params - params string
     */
    void FormFrame(CWebProtocolFrame::E_ServerCommands command, std::string params = std::string());

    /**
     * @brief FormFrameFromReceivedData - Function forming the packets from the raw data
     * @param rawData - raw data packet
     */
    void FormFrameFromReceivedData(std::string rawData);

    /**
     * @brief GetCommand - Get the command part from packet
     * @return
     */
    QByteArray GetCommand();

    /**
     * @brief GetParameters - Get the params list
     * @return
     */
    QList<QByteArray> GetParameters();

    /**
     * @brief GetFrame
     * @return
     */
    QByteArray& GetFrame();

    /**
     * @brief GetRawFrame - Get raw binary frame
     * @return
     */
    char* GetRawFrame();

    /**
     * @brief GetFrameSize - Get the frame size
     * @return
     */
    unsigned int GetFrameSize();

    /**
     * @brief GetCommandFromMap - Get the human readable form of command
     * @param cmd [in]- command type
     * @return string containing human readable form of command
     */
    static std::string GetCommandFromMap(E_ServerCommands cmd);

    /**
     * @brief GetCommandFromMap - Get the packet type from command string
     * @param cmd [in]- human readable form of packets command
     * @return
     */
    static E_ServerCommands GetCommandFromMap(std::string cmd);

    /**
     * @brief s_commandsMap - Map containing mapping the command enum type to human readable form
     */
    static std::map<E_ServerCommands, std::string>s_commandsMap;

private:

    /**
     * @brief m_setCommand - Set the command type
     * @param commandString [in]
     */
    void m_setCommand(std::string &commandString);

    /**
     * @brief m_setParameters - Set the params string
     * @param params[in]
     */
    void m_setParameters(std::string& params);

    /**
     * @brief m_frame - raw buffer containgin the frame
     */
    QByteArray m_frame;
};

#endif // WEBPROTOCOLFRAME_H
