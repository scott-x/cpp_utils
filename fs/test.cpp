/*
* @Author: scottxiong
* @Date:   2019-11-01 14:33:42
* @Last Modified by:   scottxiong
* @Last Modified time: 2019-12-02 17:47:26
*/
#include <iostream>
#include "fs.h"
using namespace std;

int main(int argc, const char * argv[]) {
    micky::FS fs;
    cout<< fs.readFile("./readme.md")<<endl;
    return 0;
}
