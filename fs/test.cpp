/*
* @Author: scottxiong
* @Date:   2019-11-01 14:33:42
* @Last Modified by:   sottxiong
* @Last Modified time: 2019-12-03 20:20:26
*/
#include <iostream>
#include "fs.h"
using namespace std;

void contenthandler(char ch){
	std::cout<<ch;
}
int main(int argc, const char * argv[]) {
    micky::FS fs;
    fs.e.contenthandler = contenthandler;
    fs.readFile("./readme.md");
    return 0;
}
