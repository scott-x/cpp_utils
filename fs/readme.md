# fs

### loop folder
```c++
#include <iostream>
#include "fs.h"
using namespace std;

void filehandler(char* file){
    std::cout<<"file:"<<file<<std::endl;
}

int main(int argc, const char * argv[]) {
    micky::FS fs;
    //扩展方法
    fs.e.filehandler = filehandler;
    fs.loop("/Volumes/datavolumn_bmkserver_Pub"); 
    return 0;
}
```

### readFile

```c++
#include <iostream>
#include "fs.h"
using namespace std;

int main(int argc, const char * argv[]) {
    micky::FS fs;
    fs.readFile("./readme.md");
    fs.readFile("/Users/apple/desktop/cpp_utils/fs/fs.h");
    return 0;
}
```