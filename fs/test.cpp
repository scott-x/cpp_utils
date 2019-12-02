/*
* @Author: scottxiong
* @Date:   2019-11-01 14:33:42
* @Last Modified by:   scottxiong
* @Last Modified time: 2019-12-02 17:01:50
*/
#include <iostream>
#include "fs.h"
using namespace std;

void filehandler(char* file){
    std::cout<<"file:"<<file<<std::endl;
}

int main(int argc, const char * argv[]) {
    micky::FS fs;
    //制定扩展方法
    fs.e.filehandler = filehandler;
    fs.loop("/Volumes/datavolumn_bmkserver_Pub"); 
    return 0;
}
