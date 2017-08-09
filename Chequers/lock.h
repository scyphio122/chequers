#ifndef LOCK_H
#define LOCK_H

#include <QMutex>

class CLock
{
public:
    CLock(QMutex* mutex);
    ~CLock();
private:
    CLock();
    QMutex* m_pMutex;
};

#endif // LOCK_H
