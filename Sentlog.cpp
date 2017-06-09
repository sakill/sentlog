//
// Created by ai on 2017/5/24.
//
#include <iostream>
#include <cstring>
#include "Sentlog.h"
#include "FileTool.h"
#include "base64.h"
#include "Out.h"
FileTool f;
//Out output;
Tool t;
OutPut o;
Option option_my;
std::string buffers="";
std::string sendbuffer="";
using namespace std;
int main(int arg,char *argv[]){
    if(t.getcmd(arg,argv)!=0) { //接收参数；
        cout << "sorry please look for your configure!" << endl;
        return 0;
    }
    f.fileinit();
    o.init();
    while(1) {
        buffers = f.getOnelineData();
        if (!(buffers == "")) {
            sendbuffer = base64_encode(reinterpret_cast<const unsigned char *>(buffers.c_str()), buffers.length());
            o.output(sendbuffer);
        }
    }
}