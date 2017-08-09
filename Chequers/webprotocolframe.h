#ifndef WEBPROTOCOLFRAME_H
#define WEBPROTOCOLFRAME_H

#include <QByteArray>

class CWebProtocolFrame
{
public:
    CWebProtocolFrame();

    void FormFrame(std::string commandString, std::string params);

    QByteArray& GetFrame();

    char* GetRawFrame();

    unsigned int GetFrameSize();
private:
    void m_setCommand(std::__cxx11::string &commandString);

    int m_setParameters(std::string params);

    QByteArray m_frame;
};

#endif // WEBPROTOCOLFRAME_H
