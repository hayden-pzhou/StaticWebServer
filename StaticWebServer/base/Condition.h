//
// Created by Hyman Zhou on 2020/7/28.
//

#ifndef STATICWEBSERVER_CONDITION_H
#define STATICWEBSERVER_CONDITION_H
#include <common.h>
#include <MutexLock.h>

class Condition :noncopyable{
public:
    explicit Condition(MutexLock& _mutex):mutex(_mutex){
        pthread_cond_init(&cond, nullptr);
    }
    ~Condition(){pthread_cond_destroy(&cond);}
    void wait() {pthread_cond_wait(&cond,mutex.get();)} //友元直接可以访问
    void notify(){pthread_cond_signal(&cond);}
    void notifyall(){pthread_cond_broadcast(&cond);}
    bool waitForSeconds(int seconds){
        struct timespec abstime;
        clock_gettime(CLOCK_REALTIME,&abstime);
        abstime.tv_nsec += static_cast<time_t>(seconds);
        return ETIMEDOUT == pthread_cond_timedwait(&cond,mutex.get(),&abstime);
    }
private:
    MutexLock& mutex;
    pthread_cond_t cond;//条件变量 cond.wait
};


#endif //STATICWEBSERVER_CONDITION_H
