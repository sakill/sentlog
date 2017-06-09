//
// Created by ai on 2017/5/24.
//

#include <unistd.h>
#include <iostream>
#include "FileTool.h"
#include "Sentlog.h"
std::string FileTool::getOnelineData() {
    point=this->ReadFile.tellg();
    if(this->point > this->point2){
        this->bakout.open(this->logbak,std::ios::out);
        this->bakout<<point<<std::endl;
        this->bakout.close();
    }
    if (std::getline(this->ReadFile,this->temp)) {
        this->ef= false;
    } else {
        this->ef= true;
        this->temp = "";
        this->ReadFile.clear();
    }
    if(this->ef){
        sleep(1);
        this->ReadFile.seekg(this->point,std::ios::beg);
    }
   // std::cout<<temp;

    return this->temp;
}

void FileTool::fileinit(){
    this->logbak=option_my.logfile;
    this->logbak+=".logbak";
    std::cout<<logbak<<std::endl;
    this->bakin.open(this->logbak,std::ios::in);
    this->filepath=option_my.logfile;
    this->ReadFile.open(this->filepath,std::ios::in);
    std::getline(bakin,this->numpoint);
    this->bakin.close();
    const char *ch=this->numpoint.c_str();
    this->point2=atol(ch);
    std::cout<<this->point2<<std::endl;
    if(this->point2>0) {
        this->ReadFile.seekg(this->point2, std::ios::beg);
    }
}