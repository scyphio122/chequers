#include "player.h"
#include <map>

std::map<CPlayer::E_PlayerStatus, std::string> CPlayer::s_statusMap =
{
    {CPlayer::E_PlayerStatus::E_INVALID, "Invalid state"},
    {CPlayer::E_PlayerStatus::E_OCCUPIED, "Player occupied"},
    {CPlayer::E_PlayerStatus::E_WAITING_FOR_PLAY, "Ready to play"}
};

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

std::string CPlayer::GetStatusString()
{
    return s_statusMap[GetStatus()];
}
