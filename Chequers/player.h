#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>

/**
 * @brief The CPlayer class - Class holding the information about each of the players logged in the server
 */
class CPlayer
{
public:
    enum class E_PlayerStatus : char
    {
        E_INVALID,
        E_WAITING_FOR_PLAY = 'A',
        E_OCCUPIED = 'B'
    };

    CPlayer();

    CPlayer(std::string playerName, E_PlayerStatus status);

    /**
     * @brief GetPlayerName
     * @return
     */
    std::string GetPlayerName();

    /**
     * @brief GetStatus
     * @return
     */
    E_PlayerStatus GetStatus();

    /**
     * @brief GetStatusString - Get the statius in the human readable form
     * @return
     */
    std::string GetStatusString();

private:
    /**
     * @brief m_playerName
     */
    std::string m_playerName;

    /**
     * @brief m_status
     */
    E_PlayerStatus m_status;

    /**
     * @brief s_statusMap - map holding a mapping between the player status and the human readable status string
     */
    static std::map<E_PlayerStatus, std::string> s_statusMap;
};

#endif // PLAYER_H
