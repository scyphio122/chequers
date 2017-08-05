#ifndef LOCK_H
#define LOCK_H

#include <QMutex>

class CLock
{
public:
    CLock();
    CLock(QMutex* mutex);
    ~CLock();
private:
    QMutex* m_pMutex;
};

#endif // LOCK_H
