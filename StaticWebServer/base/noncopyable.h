//
// Created by Hyman Zhou on 2020/7/28.
//

#ifndef STATICWEBSERVER_NONCOPYABLE_H
#define STATICWEBSERVER_NONCOPYABLE_H
class noncopyable {
protected:
    noncopyable(){}
    ~noncopyable(){}

    /**
     * 将拷贝构造和拷贝赋值私有化
     */
private:
    noncopyable(const noncopyable&);
    const noncopyable& operator=(const noncopyable&);
};
#endif //STATICWEBSERVER_NONCOPYABLE_H
