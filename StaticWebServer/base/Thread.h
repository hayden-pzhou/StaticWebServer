//
// Created by Hyman Zhou on 2020/7/28.
//

#ifndef STATICWEBSERVER_THREAD_H
#define STATICWEBSERVER_THREAD_H
#include "common.h"
#include "CountDownLatch.h"

class Thread : noncopyable {
public:
    typedef std::function<void()> ThreadFunc;
    explicit Thread(const ThreadFunc& func, const std::string& name = std::string());
    ~Thread();
    void start();
    void join();
    bool started() const {return started_;}
    pid_t tid() const {return tid_;}
    const std::string& name() const {return name_;}

private:
    void setDefaultName();
    bool started_;
    bool joined_;
    pthread_t pthreadId_;
    pid_t tid_;
    ThreadFunc func_;
    std::string name_;
    CountDownLatch latch_;
};


#endif //STATICWEBSERVER_THREAD_H
