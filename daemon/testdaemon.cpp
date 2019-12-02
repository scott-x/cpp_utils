/*
* @Author: scottxiong
* @Date:   2019-12-02 09:34:58
* @Last Modified by:   scottxiong
* @Last Modified time: 2019-12-02 09:53:48
*/
#include <iostream>
#include "daemon.h"

void run(){
  while(1){
		// sleep(1); //sleep one second
		std::cout<<"hello world"<<std::endl;
  }
}

int main(int argc, char const *argv[])
{
	micky::Server *server = new micky::Server();
	server->serve(run);
	return 0;
}