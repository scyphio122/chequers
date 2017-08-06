#include "webprotocolframe.h"
#include <QString>

CWebProtocolFrame::CWebProtocolFrame()
{

}

void CWebProtocolFrame::SetCommand(std::__cxx11::string commandString)
{
    m_frame.insert(0, QString::fromStdString(commandString));
}

void CWebProtocolFrame::SetParameters(std::__cxx11::string params)
{
    m_frame.insert(3, QString::fromStdString(params));
}

QByteArray& CWebProtocolFrame::GetFrame()
{
    return m_frame;
}
