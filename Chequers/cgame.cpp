#include "cgame.h"
#include <QThread>

static std::map<CGame::E_ServerCommands, std::string>CGame::s_commandsMap =
{
    {CGame::E_ServerCommands::E_LOGIN, "LGN"},
    {CGame::E_ServerCommands::E_REGISTER_USER, "CRA"},
    {CGame::E_ServerCommands::E_GET_PLAYERS_LIST, "LSP"},
    {CGame::E_ServerCommands::E_START_NEW_GAME, "RFP"},
    {CGame::E_ServerCommands::E_NEW_GAME_REQUESTED, "RP1"},
    {CGame::E_ServerCommands::E_NEW_GAME_REQUEST_RESPONSE, "RP2"},
    {CGame::E_ServerCommands::E_GAME_INITIALIZATION, "INI"},
    {CGame::E_ServerCommands::E_BOARD, "CHB"},
    {CGame::E_ServerCommands::E_YOUR_MOVE, "YMV"},
    {CGame::E_ServerCommands::E_RESIGN, "GVU"},
    {CGame::E_ServerCommands::E_END_GAME, "EOG"},
    {CGame::E_ServerCommands::E_LOGOUT, "LGO"},
    {CGame::E_ServerCommands::E_ERROR, "ERR"},
    {CGame::E_ServerCommands::E_INCONSISTENCY, "ERS"},
};



CGame::CGame(QObject *parent) : QObject(parent)
{
    m_userColor = E_SideColor::E_INVALID;
    m_state = E_GameState::E_NOT_INITIALIZED;

    m_thread = new QThread();

    connect(this, SIGNAL(destroyed(QObject*)), m_thread, SLOT(deleteLater()));

    this->moveToThread(m_thread);
    m_thread->start();
}

CGame* CGame::GetInstance()
{
    static CGame s_game;
    return &s_game;
}

std::string CGame::m_getCommandString(CGame::E_ServerCommands command)
{
    return s_commandsMap[command];
}
