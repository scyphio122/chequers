#ifndef WEBPROTOCOLFRAME_H
#define WEBPROTOCOLFRAME_H

#include <QByteArray>

class CWebProtocolFrame
{
public:
    CWebProtocolFrame();

    void SetCommand(std::string commandString);

    void SetParameters(std::string params);

    QByteArray& GetFrame();
private:
    QByteArray m_frame;
};

#endif // WEBPROTOCOLFRAME_H
