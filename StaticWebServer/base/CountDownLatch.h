//
// Created by Hyman Zhou on 2020/7/28.
//

#ifndef STATICWEBSERVER_COUNTDOWNLATCH_H
#define STATICWEBSERVER_COUNTDOWNLATCH_H
#include "Condition.h"
#include "MutexLock.h"
#include "noncopyable.h"

class CountDownLatch : noncopyable{
public:
    explicit CountDownLatch(int count);
    void wait();
    void countDown();

private:
    mutable MutexLock mutex_;
    Condition condition_;
    int count_;
};


#endif //STATICWEBSERVER_COUNTDOWNLATCH_H
