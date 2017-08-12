#include "player.h"

CPlayer::CPlayer()
{

}

CPlayer::CPlayer(std::__cxx11::string playerName, E_PlayerStatus status)
{
    m_playerName = playerName;
    m_status = status;
}

std::string CPlayer::GetPlayerName()
{
    return m_playerName;
}

CPlayer::E_PlayerStatus CPlayer::GetStatus()
{
    return m_status;
}
