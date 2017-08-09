#include "webprotocolframe.h"
#include <QString>

CWebProtocolFrame::CWebProtocolFrame()
{

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

void CWebProtocolFrame::m_setCommand(std::__cxx11::string& commandString)
{
    m_frame.insert(0, QString::fromStdString(commandString));


}

int CWebProtocolFrame::m_setParameters(std::__cxx11::string& params)
{
    m_frame.append("#" + params);
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


