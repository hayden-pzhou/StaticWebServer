//
// Created by Hyman Zhou on 2020/7/29.
//

#ifndef STATICWEBSERVER_LOGFILE_H
#define STATICWEBSERVER_LOGFILE_H
#include <memory>
#include <string>
#include "FileUtil.h"
#include "MutexLock.h"
#include "noncopyable.h"
/**
 * 提供自动归档功能
 */
class LogFile : noncopyable{
public:
    //每当被append flushEveryN次, flush一下，会往文件写，只不过文件也是带缓冲区的
    LogFile(const std::string& basename,int flushEveryN_=1024);
    ~LogFile();

    void append(const char* logline, int len);
    void flush();
    bool rollFile();

private:
    void append_unlocked(const char *logline,int len);

    const std::string basename_;
    const int flushEveryN_;

    int count_;
    std::unique_ptr<MutexLock> mutex_;
    std::unique_ptr<AppendFile> file_;
};


#endif //STATICWEBSERVER_LOGFILE_H
