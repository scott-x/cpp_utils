/*
* @Author: scottxiong
* @Date:   2019-11-01 14:37:34
* @Last Modified by:   scottxiong
* @Last Modified time: 2019-11-01 14:37:34
*/
#include <dirent.h>

namespace micky {
	//结构体的函数指针用于扩展class
	struct expand{
       void (*filehandler)(char *file);
	};
	class FS
	{
	public:
		FS();
		~FS();
	public:
		void loop(const char* folder);
		char* readFile(const char* filename);
	public:
		struct expand e;
	};
} // micky