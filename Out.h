//
// Created by ai on 2017/5/28.
//
#ifndef SENTLOG_OUT_H
#define SENTLOG_OUT_H
class Out {
public:
    void init();
    void redis_Command(std::string cmd);
    void redis_output(std::string value);
};
#endif //SENTLOG_OUT_H
