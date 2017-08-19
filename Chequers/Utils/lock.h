#ifndef LOCK_H
#define LOCK_H

#include <QMutex>

/**
 * @brief The CLock class - Class providin auto lock-unlock mutex functionality.
 *          When instance is being created - mutex is locked. When instance is destroyed,
 *          mutex is unlocked.
 */
class CLock
{
public:
    /**
     * @brief CLock - Constructor of the object
     * @param mutex - mutex to manage. It gets automatically locked.
     */
    CLock(QMutex* mutex);

    /**
     *  @brief Destructror - it unlocks the mutex
     */
    ~CLock();
private:
    CLock();

    /**
     * @brief m_pMutex - pointer to mutex which is to be unlocked during destruction
     */
    QMutex* m_pMutex;
};

#endif // LOCK_H
