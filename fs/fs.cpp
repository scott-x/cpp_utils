/*
* @Author: scottxiong
* @Date:   2019-11-01 14:33:33
* @Last Modified by:   scottxiong
* @Last Modified time: 2019-11-22 17:11:05
参考：http://www.lucasgabrieltutors.weinode.com/articles/71
*/
#include <stdio.h>
#include <dirent.h>
#include <iostream>
#include <typeinfo>
#include <string.h>

void loop(const char* folder);
int main(int argc, const char * argv[]) {
    const char * folder = "/Volumes/datavolumn_bmkserver_Pub";
    loop(folder);  
    return 0;
}

void loop(const char* folder){
	struct dirent *dirp;
    DIR* dir = opendir(folder);
    
    while ((dirp = readdir(dir)) != nullptr) {
        if (dirp->d_type == DT_REG && (dirp->d_name)[0]!='.') {
            // file
            printf("%s/%s\n", folder,dirp->d_name);
            
        } else if (dirp->d_type == DT_DIR) {
            // folder
            if ((dirp->d_name)[0]=='.') {
            	continue;
            }
            // const char* a= *folder+"/H2R";
            int length = strlen(folder)+strlen(dirp->d_name)+2;
            // std::cout<< "length:"<<length <<std::endl;
            char * a = new char[length];
            char *p = a;
         
            for (int i = 0; i < length; i++,p++)
            {
            	*p = folder[i];
            	if (i<=strlen(folder)){
            		*p = folder[i];
            	}

            	if (i==strlen(folder)){
            		*p = '/';
            	}
            	if (i>strlen(folder) && i < length){
            		*p =(dirp->d_name)[i-strlen(folder)-1] ;
            	}
            	if (i==length) {
            		*p = '\0';
            	}
            }
            // std::cout<<"a:"<<a <<  std::endl; 
            loop(a);
            delete[] a;
            p=NULL;
            // std::cout<<"folder:"<< dirp->d_name <<  std::endl;
        }
    }
    
    closedir(dir);
}