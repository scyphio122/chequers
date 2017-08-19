#ifndef PROTOCOLFRAMEPARSER_H
#define PROTOCOLFRAMEPARSER_H

#include <QObject>
#include <QList>
#include <QByteArray>
#include "webprotocolframe.h"
#include "player.h"

/**
 * @brief The CProtocolFrameParser class - SINGLETON Class responsible for parsing the incoming from the server packets
 */
class CProtocolFrameParser : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief GetInstance - Get instance of frame parser
     * @return
     */
    static CProtocolFrameParser* GetInstance();

signals:
    /**
     * @brief signalLoginRetval - signal emitted when login response was received
     * @param success true if successfully logged in, false otherwise
     */
    void signalLoginRetval(bool success);

    /**
     * @brief signalRegisterRetval - signal emitted when the user register response was received
     * @param success true if user registered, false otherwise
     */
    void signalRegisterRetval(bool success);

    /**
     * @brief signalListOfPlayersReceived - signal emitted when the list of players is received
     * @param playersList [in] - received players list
     */
    void signalListOfPlayersReceived(QList<CPlayer> playersList);

    /**
     * @brief signalNewGameRequestPassed - signal emitted when the new game request server response is received
     * @param result - 1 if request passed to player, 0 itherwise
     */
    void signalNewGameRequestPassed(int result);

    /**
     * @brief signalNewGameRequested - signal emitted when the new game invitation is received
     * @param hostPlayerName - username of the player who invites the user
     */
    void signalNewGameRequested(std::string hostPlayerName);

    /**
     * @brief signalNewGameRequestResponse - signal emitted when the player has responded to the new game request
     * @param result - 1 if request accepted, 0 if declined
     */
    void signalNewGameRequestResponse(int result);

    /**
     * @brief signalGameInitialization - signal emitted when server initializes the game
     * @param playerColor - color of the side assigned to the user
     */
    void signalGameInitialization(char playerColor);

    /**
     * @brief signalBoardReceived - signal emitted when the server sends the board layout
     * @param board[in] - char[8][8]
     */
    void signalBoardReceived(char* board);

    /**
     * @brief signalYourMove - signal emitted when the server notifies about the user's move
     * @param status
     */
    void signalYourMove(bool status);

    /**
     * @brief signalGameEnded - signal emitted when the game has anded
     * @param result - username of the player who won
     * @param reason - reason of the game end
     */
    void signalGameEnded(std::string result, std::string reason);

    /**
     * @brief signalMakeMoveServerResponse - signal emitted when the server responds to the user made move
     * @param result - 1 if move accepted, 0 if declined
     */
    void signalMakeMoveServerResponse(int result);

public slots:
    /**
     * @brief Parse - Function parsing the raw packet
     * @param receivedData [in] - row packet of data
     */
    void Parse(QByteArray receivedData);

private:
    CProtocolFrameParser();

    /**
     * @brief m_getFrames - function which splits the raw packet into commands
     * @param receivedBuffer [in]- raw data packet
     * @return list of commands
     */
    QList<QByteArray> m_getFrames(QByteArray receivedBuffer);

    /**
     * @brief m_formFrame - Function forming frames from commands
     * @param singleFrame - frame to be formed
     * @return
     */
    CWebProtocolFrame m_formFrame(QByteArray& singleFrame);

    /**
     * @brief m_parseFrame - Main parsing function
     * @param frame [in]- frame to be parsed
     */
    void m_parseFrame(CWebProtocolFrame& frame);

    /// Buffer containing data which could not be parsed into full protocol packets/messages
    QByteArray m_partialData;
};

#endif // PROTOCOLFRAMEPARSER_H
