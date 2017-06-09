//
// Created by ai on 2017/5/28.
//

#include <iostream>
#include <cstring>
#include <unistd.h>
#include "lib/hiredis/hiredis.h"
#include "Sentlog.h"
#include "Out.h"
redisContext *conn;
std::string logrediskey;
void Out::init() {
    if (strcmp(option_my.outputype, "redis") == 0) {
        conn=redisConnect(option_my.redishost,6379);
        if(conn != NULL && conn->err)
        {
            std::cout << "connection error: %s\n" << conn->errstr << std::endl;
            exit(-1);
        }
        std::string pass="auth ";
        pass+=option_my.redispassword;
        redisReply *reply = (redisReply*)redisCommand(conn,pass.c_str());
        if(strcmp(reply->str,"OK")==0){
            std::cout<<"password correct"<<std::endl;
        } else{
            std::cout<<"password is not correct"<<std::endl;
        }
    }
    logrediskey=option_my.logrediskey;
}


void Out::redis_output(std::string value) {
    this->redis_Command("lpush "+logrediskey+ " "+value);
}


void Out::redis_Command(std::string cmd) {
    redisReply *reply = (redisReply*)redisCommand(conn,cmd.c_str());
    redisFree(conn);
}