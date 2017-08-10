#include "protocolframeparser.h"
#include <QList>
#include <QByteArray>
#include "webprotocolframe.h"
#include "logger.h"

CProtocolFrameParser::CProtocolFrameParser()
{

}

CProtocolFrameParser* CProtocolFrameParser::GetInstance()
{
    static CProtocolFrameParser s_instance;
    return &s_instance;
}

void CProtocolFrameParser::Parse(QByteArray receivedData)
{
        QList<QByteArray> listOfFrames = m_getFrames(receivedData);

        for (int i=0; i<listOfFrames.size(); ++i)
        {
            CWebProtocolFrame frame = m_formFrame(listOfFrames[i]);

            m_parseFrame(frame);
        }
}

QList<QByteArray> CProtocolFrameParser::m_getFrames(QByteArray receivedBuffer)
{
    QList<QByteArray> packets = receivedBuffer.split('\n');

    // Remove the '\r' char if included
    for(int i=0; i<packets.size(); ++i)
    {
        packets[i] = packets[i].split('\r')[0];
    }

    for (int i=0; i<packets.size(); ++i)
    {
        if (packets[i].size() == 0)
        {
            packets.removeAt(i);
        }
    }
    return packets;
}

CWebProtocolFrame CProtocolFrameParser::m_formFrame(QByteArray& singleFrame)
{
    CWebProtocolFrame frame;
    frame.FormFrameFromReceivedData(singleFrame.toStdString());
    return frame;
}

void CProtocolFrameParser::m_parseFrame(CWebProtocolFrame& frame)
{

    std::string cmd = frame.GetCommand().toStdString();
    QList<QByteArray> params = frame.GetParameters();
    LOG_DBG("CMD: %s, paramsSize: %d", cmd, params.size());

    CWebProtocolFrame::E_ServerCommands commandEnum = CWebProtocolFrame::GetCommandFromMap(cmd);

    switch (commandEnum)
    {
        case CWebProtocolFrame::E_ServerCommands::E_LOGIN:
            {
                if (!params.empty())
                {
                    int loginSuccess = params[0].toUShort();
                    LOG_DBG("Login %s", loginSuccess? "success" : "fail");

                    emit signalLoginRetval((bool)loginSuccess);
                }
                else
                {
                    LOG_FATAL("Wrong number of parameters");
                }
            }break;

        case CWebProtocolFrame::E_ServerCommands::E_REGISTER_USER:
            {
                if (!params.empty())
                {
                    int registerSuccess = params[0].toUShort();
                    LOG_DBG("Register %s", registerSuccess? "success" : "fail");

                    emit signalRegisterRetval((bool)registerSuccess);
                }
                else
                {
                    LOG_FATAL("Wrong number of parameters");
                }
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
                if (!params.empty())
                {
                    std::string newGamePlayerName = params[0].toStdString();
                    LOG_DBG("PLayer: '%s' has requested new game", newGamePlayerName.c_str());

                    emit signalNewGameRequested(newGamePlayerName);
                }
                else
                {
                    LOG_FATAL("Wrong number of parameters");
                }
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
