/*
* @Author: scottxiong
* @Date:   2019-11-01 14:37:34
* @Last Modified by:   scottxiong
* @Last Modified time: 2019-11-01 14:37:34
*/

#ifndef __TIME_H__
#define __TIME_H__

#include <unistd.h>
namespace micky {
	void Sleep(unsigned int second){
		sleep(second);
	}
} // micky

#endif