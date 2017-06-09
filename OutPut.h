//
// Created by ai on 2017/6/8.
//

#ifndef SENTLOG_OUTPUT_H
#define SENTLOG_OUTPUT_H


#include <string>
#include "lib/hiredis/hiredis.h"  //调用redis的头文件

class OutPut {
    void screen_output(std::string value); //定义屏幕输出

    void redis_output(std::string value); //redis 输出。
public:
    redisContext *redis;
    bool redisinited;
    redisReply *redisreply;

    void init();
    void output(std::string value);
    void redisinit();

    std::string redis_Command(std::string cmd);

    std::string logrediskey;   //设定key值
};


#endif //SENTLOG_OUTPUT_H
