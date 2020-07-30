//
// Created by Hyman Zhou on 2020/7/28.
//
#include "../Thread.h"
#include <string>
#include <unistd.h>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

void threadFunction(){
    for(int i=0;i<100;i++){
        cout << i <<endl;
    }
}

int main(){
    shared_ptr<Thread> tmp(new Thread(threadFunction,"testFunc"));
    tmp->start();
    tmp->join();
    cout << "main thread waiting" << endl;
}

