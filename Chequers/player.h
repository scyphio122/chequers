#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class CPlayer
{
public:
    CPlayer();
    CPlayer(std::string playerName, E_PlayerStatus status);

    enum class E_PlayerStatus : char
    {
        E_INVALID,
        E_WAITING_FOR_PLAY = 'A',
        E_OCCUPIED = 'B'
    };

    std::string GetPlayerName();

    E_PlayerStatus GetStatus();

private:
    std::string m_playerName;
    E_PlayerStatus m_status;
};

#endif // PLAYER_H
