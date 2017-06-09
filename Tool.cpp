//
// Created by ai on 2017/5/24.
//
#include <iostream>
#include <getopt.h>
#include <cstring>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include "Tool.h"
#include "Sentlog.h"
int Tool::getcmd(int arg,char *argv[]){
    int opt;
    const struct option long_options[] = {
            {"logfile",        required_argument, NULL, CONFIG_LOGFILE},
            {"outputype",      required_argument, NULL, CONFIG_OUTPUTYPE},
            {"redis_host",     required_argument, NULL, CONFIG_REDISHOST},
            {"redis_port",     required_argument, NULL, CONFIG_REDISPORT},
            {"redis_password", required_argument, NULL, CONFIG_REDISPASSWORD},
            {"logrediskey",    required_argument, NULL, CONFIG_LOGREDISKEY},
            {"pushbuffernum",  required_argument, NULL, CONFIG_PUSHBUFFERNUM},
            {"readrow",        required_argument, NULL, CONFIG_READROW},
            {"redis_maxnum",   required_argument, NULL, CONFIG_REDISMAXNUM},
    };

    while ((opt = getopt_long(arg, argv, "", long_options, NULL)) != -1) {
        switch (opt) {
            case CONFIG_LOGFILE:
                option_my.logfile = optarg;
                break;
            case CONFIG_OUTPUTYPE:
                option_my.outputype = optarg;
                break;
            case CONFIG_REDISHOST:
                option_my.redishost = optarg;
                break;
            case CONFIG_REDISPORT:
                option_my.redisport = optarg;
                break;
            case CONFIG_REDISPASSWORD:
                option_my.redispassword = optarg;
                break;
            case CONFIG_LOGREDISKEY:
                option_my.logrediskey = optarg;
                break;
            case CONFIG_PUSHBUFFERNUM:
                option_my.ppushbuffernum = optarg;
                break;
            case CONFIG_READROW:
                option_my.preadrow = optarg;
                break;
            case CONFIG_REDISMAXNUM:
                option_my.predismaxnum = optarg;
                break;
            default:
                return -1;
        }
    }
    if (option_my.logfile == NULL || option_my.outputype == NULL) {
        Tool::usage();
        return -1;
    }
    option_my.pushbuffernum = atol(option_my.ppushbuffernum);  //字符转换为数值
    option_my.readrow = atol(option_my.preadrow);      //字符转换为数值
    option_my.redismaxnum = atol(option_my.predismaxnum);  //字符转换为数值
    return 0;
}

void Tool::usage() {  //参数提示设置。
    puts("Usage:LogCollector --logfile pathtolog");
    puts("                   --outputype [screen|redis]");
    puts("                   --redis_host host");
}
