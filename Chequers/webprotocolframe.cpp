#include "webprotocolframe.h"
#include <QString>
#include <QList>
#include <QByteArray>

#define PACKET_SEPARATOR "#"

std::map<CWebProtocolFrame::E_ServerCommands, std::string>CWebProtocolFrame::s_commandsMap =
{
    {CWebProtocolFrame::E_ServerCommands::E_LOGIN, "LGN"},
    {CWebProtocolFrame::E_ServerCommands::E_REGISTER_USER, "CRA"},
    {CWebProtocolFrame::E_ServerCommands::E_GET_PLAYERS_LIST, "LSP"},
    {CWebProtocolFrame::E_ServerCommands::E_START_NEW_GAME, "RFP"},
    {CWebProtocolFrame::E_ServerCommands::E_NEW_GAME_REQUESTED, "RP1"},
    {CWebProtocolFrame::E_ServerCommands::E_NEW_GAME_REQUEST_RESPONSE, "RP2"},
    {CWebProtocolFrame::E_ServerCommands::E_GAME_INITIALIZATION, "INI"},
    {CWebProtocolFrame::E_ServerCommands::E_BOARD, "CHB"},
    {CWebProtocolFrame::E_ServerCommands::E_YOUR_MOVE, "YMV"},
    {CWebProtocolFrame::E_ServerCommands::E_RESIGN, "GVU"},
    {CWebProtocolFrame::E_ServerCommands::E_END_GAME, "EOG"},
    {CWebProtocolFrame::E_ServerCommands::E_LOGOUT, "LGO"},
    {CWebProtocolFrame::E_ServerCommands::E_ERROR, "ERR"},
    {CWebProtocolFrame::E_ServerCommands::E_INCONSISTENCY, "ERS"},
};

CWebProtocolFrame::CWebProtocolFrame()
{
    m_frame.clear();
}

void CWebProtocolFrame::FormFrame(std::string commandString, std::string params = "")
{
    m_setCommand(commandString);
    if (!params.empty())
    {
        m_setParameters(params);
    }
    m_frame.append("\r\n");
}

void CWebProtocolFrame::FormFrameFromReceivedData(std::string rawData)
{
    int index = rawData.find("\r\n");

    if (index != -1)
    {
        rawData.erase(index, 2);
    }

    m_frame.append(QString::fromStdString(rawData));
}

QByteArray& CWebProtocolFrame::GetFrame()
{
    return m_frame;
}

char* CWebProtocolFrame::GetRawFrame()
{
    return m_frame.data();
}

unsigned int CWebProtocolFrame::GetFrameSize()
{
    return m_frame.size();
}

QByteArray CWebProtocolFrame::GetCommand()
{
    QList<QByteArray> cmd = m_frame.split(PACKET_SEPARATOR[0]);
    return cmd[0];
}

std::string CWebProtocolFrame::GetCommandFromMap(E_ServerCommands cmd)
{
    return s_commandsMap[cmd];
}

CWebProtocolFrame::E_ServerCommands CWebProtocolFrame::GetCommandFromMap(std::string cmd)
{
    for(std::map<E_ServerCommands, std::string>::iterator i=s_commandsMap.begin(); i != s_commandsMap.end(); ++i)
    {
        if (i->second == cmd)
            return i->first;
    }

    return E_ServerCommands::E_UNDEFINED;
}

QList<QByteArray> CWebProtocolFrame::GetParameters()
{
    QList<QByteArray> params = m_frame.split(PACKET_SEPARATOR[0]);
    params.pop_front();
    return params;
}

void CWebProtocolFrame::m_setCommand(std::string& commandString)
{
    m_frame.insert(0, QString::fromStdString(commandString));
}

void CWebProtocolFrame::m_setParameters(std::string& params)
{
    m_frame.append(PACKET_SEPARATOR);
    m_frame.append(QString::fromStdString(params));
}

