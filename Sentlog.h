//
// Created by ai on 2017/5/24.
//

#ifndef SENTLOG_SENTLOG_H
#define SENTLOG_SENTLOG_H
#include "Tool.h"
#include "FileTool.h"
#include "OutPut.h"
typedef struct options { //创建一个结构体。
    char *logfile = NULL;
    char *readtype = NULL;
    char *outputype = NULL;
    char *redishost = NULL;
    char *redisport = NULL;
    char *redispassword = NULL;
    char *logrediskey = NULL;
    char *ppushbuffernum = NULL;
    long pushbuffernum = 1;
    char *preadrow = NULL;
    long readrow = 0;
    char *predismaxnum;
    long redismaxnum = 0;
} Option;

enum {      //设置一个枚举
    CONFIG_LOGREDISKEY, //redis key
    CONFIG_OUTPUTYPE,  // 输出类型
    CONFIG_LOGFILE,  //日志文件
    CONFIG_REDISHOST, //redis 主机host
    CONFIG_REDISPORT, //redis服务器端口
    CONFIG_REDISPASSWORD, //redis 服务器密码
    CONFIG_PUSHBUFFERNUM, //
    CONFIG_READROW,
    CONFIG_REDISMAXNUM
};

extern Option option_my; //定义一个结构体 option_my
//extern Tool t;
extern FileTool f;
extern OutPut o;
#endif //SENTLOG_SENTLOG_H
