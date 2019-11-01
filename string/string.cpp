/*
* @Author: scottxiong
* @Date:   2019-11-01 10:40:23
* @Last Modified by:   scottxiong
* @Last Modified time: 2019-11-01 14:49:17
*/
#include <string>
#include "string.h"

char *toUpper(char *str){
   char * addr = str;
   int length = strlen(str);
   for (int i = 0; i < length; i++, str++)
   {
   	  if (*str>=97 && *str<=122) {
   	  	*str -= 32;
   	  }
   }
   return addr;
}

char *toLower(char *str){
  char * addr = str;
  int length = strlen(str);
  for (int i = 0; i < length; i++, str++)
   {
   	  if (*str>=65 && *str<=90) {
   	  	*str += 32;
   	  }
   }
  return addr;
};

char *firstLetterToUpper(char *str){
  str = toLower(str);
  char * addr  = str;
  int length = strlen(str);
  for (int i = 0; i < length; i++,str++)
  {
  	if (i==0) *str -=32;
  	if (*str==32 && *(str+1)>=97 && *(str+1)<=122 ) {
  		*(str+1) -=32;
  	} 
  }
  return addr;
};

int counts(char *str){
	return strlen(str);
};

int index(char *str, char * substr){
	int result = -1;
	int strleng = strlen(str);
  int subleng = strlen(substr);
  if (subleng > strleng){
    return result;
  }
	char *p1, *p2;
	p1 = str;
	p2 = substr;
	for (int i = 0; i < strleng; i++, p1++)
	{
		if (*p1 == *p2) {
		    p2++;
	    }else{
            p2 = substr;
	    }
	    if (*p2=='\0'){
			result = i-strlen(substr)+1;
			break;
	   }
		
	}
    return result;
};

void replace(char *str, std::string from, std::string to){
  
};