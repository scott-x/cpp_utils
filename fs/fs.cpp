/*
* @Author: scottxiong
* @Date:   2019-11-01 14:33:33
* @Last Modified by:   scottxiong
* @Last Modified time: 2019-12-02 18:01:38
ref：http://www.lucasgabrieltutors.weinode.com/articles/71
*/
#include <stdio.h>
#include <dirent.h>
#include <iostream>
#include <typeinfo>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include "fs.h"

namespace micky {
    FS::FS()
    {

    }
    FS::~FS(){
        //destructor
        // std::cout<<"destructor..."<<std::endl;
    }
    void FS::loop(const char* folder){
        struct dirent *dirp;
        DIR* dir = opendir(folder);
        while ((dirp = readdir(dir)) != nullptr) {
             if (dirp->d_type == DT_REG && (dirp->d_name)[0]!='.') {
                 // file
                int len = sizeof(folder)+sizeof(dirp->d_name)+2;
                char *file = new char[len];
                strcpy(file,folder);
                strcat(file,"/");
                strcat(file,dirp->d_name);
                (e.filehandler)(file); 
                delete[] file;               
             } else if (dirp->d_type == DT_DIR) {
                 // folder
                 if ((dirp->d_name)[0]=='.') {
                     continue;
                 }
                 int length = strlen(folder)+strlen(dirp->d_name)+2;
                 char * a = new char[length];
                 strcpy(a,folder);
                 strcat(a,"/");
                 strcat(a,dirp->d_name);
                 // std::cout<<"a:"<<a <<  std::endl;
                 // std::cout<<"dirp->d_name:"<<dirp->d_name<<  std::endl;
                 loop(a);
                 delete[] a;
             } 
        } 
        closedir(dir);
    }

    char* FS::readFile(const char* filename){
        FILE * fp;
        char ch;
        char *content = (char *)malloc(sizeof(char));
        if (content==NULL){
            return NULL;
        }
        char* p = content;
        //open
        fp = fopen(filename,"r");
        if (fp==NULL) {
            printf("fail to open %s \n", filename);
            return NULL;
        }
        //如果没到文件尾部，一致读取
        while((ch = fgetc(fp)) != EOF){
           // putchar(ch);//fgetc一次只能读取一个字符；putchar显示
           *p = ch;
           p= (char *)realloc(p, 256);
        }
        //close
        fclose(fp);
        return content;
    }
} // micky
