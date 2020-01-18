/*
* @Author: scottxiong
* @Date:   2019-11-01 14:37:34
* @Last Modified by:   scottxiong
* @Last Modified time: 2019-11-01 14:37:34
*/
#ifndef __CMD_H__
#define __CMD_H__
#include "../cl/cl.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <map> 

//https://blog.csdn.net/weixin_42405632/article/details/88563221
namespace micky {
	
	std::map<std::string, std::string> qs;
	void AskQuestion(std::string key, const char * question){
		printf("\033[01;32m%s: \033[0m\n",question);
		std::string answer;
		getline(std::cin,answer);
		qs[key] = answer;
	}

	void ShowMenu(std::string tips, std::string selections[], int length){
		printf("\033[01;31m%s \033[0m\n",tips.c_str());
		for (int i =0; i< length; i++) {
			printf("\033[01;32m%s \033[0m\n",selections[i].c_str());
		}
	}

	void Print(color c, std::string str){
		switch(c){
			case GREEN:
				printf("\033[01;32m%s\033[0m\n",str.c_str());
				break;
			case RED:
				printf("\033[01;31m%s\033[0m\n",str.c_str());
				break;	
			case BLUE:
				printf("\033[01;34m%s\033[0m\n",str.c_str());
				break;
			case PURPLE:
				printf("\033[01;35m%s\033[0m\n",str.c_str());
				break;	
			case YELLOW:
				printf("\033[01;33m%s\033[0m\n",str.c_str());
				break;	
			case WHITE:
				printf("\033[01;37m%s\033[0m\n",str.c_str());
				break;	
			case FLASH: //闪烁
				printf("\033[5m%s\033[0m\n",str.c_str());
				break;	
			case BGRED: //red background
				printf("\033[01;46m%s\033[0m\n",str.c_str());
				break;	
			case BGTEER: //天蓝色background
				printf("\033[01;46m%s\033[0m\n",str.c_str());
				break;																				
			default:
				printf("\033[01;34m%s\033[0m\n",str.c_str());
				break;
		}
		
	}
	void PrintInfo(std::string str) {
		printf("\033[01;33minfo: \033[0m");
		printf("\033[01;32m%s\033[0m\n",str.c_str());
	}

	void PrintWarning(std::string str) {
		printf("\033[01;31mwarning: \033[0m");
		printf("\033[01;32m%s\033[0m\n",str.c_str());
	}

} // micky

#endif