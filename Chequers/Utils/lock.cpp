#include "lock.h"

//CLock::CLock()
//{

//}

CLock::CLock(QMutex* mutex)
{
    m_pMutex = mutex;
    mutex->lock();
}

CLock::~CLock()
{
    m_pMutex->unlock();
}
