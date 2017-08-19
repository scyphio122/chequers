#include "webmanager.h"
#include "logger.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "lock.h"
#include <QMutex>

QMutex* CWebManager::s_pWebMutex = nullptr;

#define NET_MUTEX_LOCK CLock(CWebManager::s_pWebMutex)

CWebManager::CWebManager()
{
    m_networkThread = new QThread(this);
    this->moveToThread(m_networkThread);

    connect(this, SIGNAL(destroyed(QObject*)), m_networkThread, SLOT(deleteLater()));
    m_networkThread->start();

    m_isConnected = false;
    m_socketDescriptor = -1;
    s_pWebMutex = new QMutex();

    m_pReceiveTimer = new QTimer();
    m_pReceiveTimer->setInterval(M_RECEIVE_TIMEOUT_MS);
    m_pReceiveTimer->setSingleShot(false);
    m_pReceiveTimer->setParent(this);
    connect(m_pReceiveTimer, SIGNAL(timeout()), this, SLOT(m_getDataIfAvailable()));
    m_pReceiveTimer->start();
}

CWebManager* CWebManager::GetInstance()
{
    static CWebManager s_instance;
    return &s_instance;
}

CWebManager::~CWebManager()
{
    delete s_pWebMutex;
    delete m_pReceiveTimer;
    Disconnect();
    delete m_networkThread;
}

bool CWebManager::Connect(std::__cxx11::string ip)
{
    if (m_isConnected)
    {
        LOG_WARNING("Already connected: m_socketDescriptor: %d", m_socketDescriptor);
        return false;
    }
    m_socketDescriptor = socket(AF_INET , SOCK_STREAM , 0);

    if (m_socketDescriptor == -1)
    {
        LOG_CRITICAL("Could not create socket. m_socketDescriptror: %d", m_socketDescriptor);
        return false;
    }

    m_serverIpAddress = ip;
    LOG_DBG("Trying to connect to IP: \'%s\', socketDescriptor: %d", ip.c_str(), m_socketDescriptor);

    if (!m_connect())
    {
        LOG_CRITICAL("Connecting failed.");
    }

    LOG_DBG("Connected successfully");
    m_isConnected = true;

    return true;
}

bool CWebManager::Disconnect()
{
    NET_MUTEX_LOCK;
    LOG_DBG(" ");
    // Close the socket
    close(m_socketDescriptor);
    m_socketDescriptor = -1;
    m_isConnected = false;

    return true;
}

int CWebManager::SendData(void *data, int dataSize)
{
    NET_MUTEX_LOCK;
    if (!m_isConnected)
    {
        LOG_CRITICAL("Not connected. Returning");
        return 0;
    }

    // Write data to the socket
    int size = write(m_socketDescriptor, data, dataSize);
   return size;
}

void CWebManager::ReadDataSynchroneous(QByteArray& response)
{
    NET_MUTEX_LOCK;
    char buf[M_RECEIVE_DATA_BUFFER_SIZE];
    int size = 0;

    do
    {
        size = recv(m_socketDescriptor, buf, M_RECEIVE_DATA_BUFFER_SIZE, 0);

        if (size == -1)
        {
            if (!(errno == EWOULDBLOCK || errno == EAGAIN))
            {
                LOG_ERRNO();
            }
            return;
        }

        if (size == 0)
        {
            response.clear();
            return;
        }

        response.append(buf);

    }while (size != 0);

}

bool CWebManager::m_startCyclicReceiveCheck()
{
    if (m_pReceiveTimer->isActive())
        return false;

    m_pReceiveTimer->setInterval(M_RECEIVE_TIMEOUT_MS);
    m_pReceiveTimer->setSingleShot(true);
    m_pReceiveTimer->start();

    return true;
}

void CWebManager::m_cancelCyclicReceiveCheck()
{
    m_pReceiveTimer->stop();
}

void CWebManager::m_getDataIfAvailable()
{
    NET_MUTEX_LOCK;

    QByteArray receivedData;
    int size = 0;

    do
    {
        memset(m_receiveBuf, 0 , M_RECEIVE_DATA_BUFFER_SIZE);
        size = recv(m_socketDescriptor, m_receiveBuf, M_RECEIVE_DATA_BUFFER_SIZE, MSG_DONTWAIT);

        if (size == -1)
        {
            if (!(errno == EWOULDBLOCK || errno == EAGAIN))
            {
                LOG_ERRNO();
                return;
            }
            break;
        }

        if (size == 0)
        {
           break;
        }

        receivedData.append(m_receiveBuf, size);

    }while (size != 0);

    emit signalDataAvailable(receivedData);
}

bool CWebManager::m_connect()
{
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(m_serverIpAddress.c_str());
    server.sin_port = htons(M_SERVER_PORT);

    if (::connect(m_socketDescriptor, (sockaddr*)&server, sizeof(server)) == -1)
    {
        LOG_CRITICAL("Could not connect to server.");
        return false;
    }

    return true;
}
