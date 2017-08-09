#include "protocolframeparser.h"
#include <QList>
#include <QByteArray>
#include "webprotocolframe.h"


CProtocolFrameParser::CProtocolFrameParser()
{

}

CProtocolFrameParser* CProtocolFrameParser::GetInstance()
{
    static CProtocolFrameParser s_instance;
    return &s_instance;
}

QList<QByteArray> CProtocolFrameParser::m_getFrames(QByteArray receivedBuffer)
{
    QList<QByteArray> packets = receivedBuffer.split('\n');

    // Remove the '\r' char if included
    for(int i=0; i<packets.size(); ++i)
    {
        packets[i] = packets[i].split('\r')[0];
    }
    return packets;
}

CWebProtocolFrame CProtocolFrameParser::m_getSingleFrame(QByteArray& singleFrame)
{
    CWebProtocolFrame frame;
    frame.FormFrameFromReceivedData(singleFrame.toStdString());
    return frame;
}

void CProtocolFrameParser::m_parseFrame(CWebProtocolFrame& frame)
{
    std::string cmd = frame.GetCommand().toStdString();
    QList<QByteArray> params = frame.GetParameters();

    CWebProtocolFrame::E_ServerCommands commandEnum = CWebProtocolFrame::GetCommandFromMap(cmd);

    switch (commandEnum)
    {
        case CWebProtocolFrame::E_ServerCommands::E_LOGIN:
        {

        }break;

        case CWebProtocolFrame::E_ServerCommands::E_REGISTER_USER:
        {

        }break;

        case CWebProtocolFrame::E_ServerCommands::E_BOARD:
        {

        }break;

        case CWebProtocolFrame::E_ServerCommands::E_END_GAME:
        {

        }break;

        case CWebProtocolFrame::E_ServerCommands::E_ERROR:
        {

        }break;

        case CWebProtocolFrame::E_ServerCommands::E_GAME_INITIALIZATION:
        {

        }break;

        case CWebProtocolFrame::E_ServerCommands::E_GET_PLAYERS_LIST:
        {

        }break;

        case CWebProtocolFrame::E_ServerCommands::E_INCONSISTENCY:
        {

        }break;

        case CWebProtocolFrame::E_ServerCommands::E_LOGOUT:
        {

        }break;

        case CWebProtocolFrame::E_ServerCommands::E_NEW_GAME_REQUESTED:
        {

        }break;

        case CWebProtocolFrame::E_ServerCommands::E_NEW_GAME_REQUEST_RESPONSE:
        {

        }break;

        case CWebProtocolFrame::E_ServerCommands::E_RESIGN:
        {

        }break;

        case CWebProtocolFrame::E_ServerCommands::E_START_NEW_GAME:
        {

        }break;

        case CWebProtocolFrame::E_ServerCommands::E_YOUR_MOVE:
        {

        }break;

        default:
        {

        }break;
    }
}
