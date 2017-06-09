//
// Created by ai on 2017/5/24.
//

#ifndef SENTLOG_FILETOOL_H
#define SENTLOG_FILETOOL_H
#include   <fstream>
class FileTool {
public:
    char *filepath;
    bool ef;
    std::string temp,numpoint,logbak;
    std::streampos point,point2;
    std::fstream ReadFile,bakin,bakout; //readfile 的一个文本
    int checkfile();
    std::string getOnelineData();
    void fileinit();
};


#endif //SENTLOG_FILETOOL_H
