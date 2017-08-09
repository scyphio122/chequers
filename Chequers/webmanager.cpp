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

    m_isConnected = false;
    m_serverResponseTimeout = false;
    m_socketDescriptor = -1;
    s_pWebMutex = new QMutex();

//    m_pReceiveTimer = new QTimer();
//    m_pReceiveTimer->setInterval(M_RECEIVE_TIMEOUT_MS);
//    m_pReceiveTimer->setSingleShot(false);
//    connect(m_pReceiveTimer, SIGNAL(timeout()), this, SLOT(m_getDataIfAvailable()));
//    m_pReceiveTimer->start();

    m_receiveDataArray.resize(M_RECEIVE_DATA_BUFFER_SIZE);

    m_networkThread->start();
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

   int size = write(m_socketDescriptor, data, dataSize);//send(m_socketDescriptor, data, dataSize, 0);
   return size;
}

void CWebManager::ReadDataSynchroneous(QByteArray& response)
{
    NET_MUTEX_LOCK;

    int size = recv(m_socketDescriptor, m_receiveDataArray.data(), M_RECEIVE_DATA_BUFFER_SIZE, 0);

    if (size == -1)
    {
        if (!(errno == EWOULDBLOCK || errno == EAGAIN))
        {
            LOG_ERRNO();
        }
        return;
    }

    response.clear();
    response.append(m_receiveDataArray);
}

bool CWebManager::m_startReceiveTimeout()
{
    if (m_pReceiveTimer->isActive())
        return false;

    m_serverResponseTimeout = false;
    m_pReceiveTimer->setInterval(M_RECEIVE_TIMEOUT_MS);
    m_pReceiveTimer->setSingleShot(true);
    m_pReceiveTimer->start();

    return true;
}

void CWebManager::m_cancelReceiveTimeout()
{
    m_pReceiveTimer->stop();
    m_serverResponseTimeout = false;
}

void CWebManager::m_receiveTimerTimeoutCallback()
{
    m_serverResponseTimeout = true;
}

void CWebManager::m_getDataIfAvailable()
{
    NET_MUTEX_LOCK;
    int size = recv(m_socketDescriptor, m_receiveDataArray.data(), M_RECEIVE_DATA_BUFFER_SIZE, MSG_DONTWAIT);

    if (size == -1)
    {
        if (!(errno == EWOULDBLOCK || errno == EAGAIN))
        {
            LOG_ERRNO();
        }
        return;
    }

    emit signalDataAvailable(&m_receiveDataArray, size);
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
