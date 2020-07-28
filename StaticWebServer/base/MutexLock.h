//
// Created by Hyman Zhou on 2020/7/28.
//

#ifndef STATICWEBSERVER_MUTEXLOCK_H
#define STATICWEBSERVER_MUTEXLOCK_H
#include <common.h>
#include <cstdio>

class MutexLock : noncopyable{
public:
    MutexLock(){pthread_mutex_init(&mutex, nullptr)} //初始化一把锁
    ~MutexLock(){
        pthread_mutex_lock(&mutex);
        pthread_mutex_destroy(&mutex);
    }
    void lock(){pthread_mutex_lock(&mutex);}
    void unlock(){pthread_mutex_unlock(&mutex);}
    pthread_mutex_t * get(){return &mutex}

private:
    pthread_mutex_t mutex;
private:
    friend class Condition;
};
/**
 * 使用RAII管理锁
 */
class MutexLockGuard : noncopyable{
public:
    MutexLockGuard(MutexLock& _mutex):mutex(_mutex){mutex.lock();}
    ~MutexLockGuard(){mutex.unlock();} //释放锁
private:
    MutexLock& mutex;
};


#endif //STATICWEBSERVER_MUTEXLOCK_H
