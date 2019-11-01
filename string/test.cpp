/*
* @Author: scottxiong
* @Date:   2019-11-01 10:40:32
* @Last Modified by:   scottxiong
* @Last Modified time: 2019-11-01 11:57:55
*/
#include <iostream>
#include "string.h"
using namespace std;

int main(int argc, char const *argv[])
{
	char name[] = "Scott xiong";
	cout<<toUpper(name)<<endl; //SCOTT XIONG
	char name1[] = "SCOTT XiONG";
	cout << toLower(name1) << endl; //scott xiong
	char name3[] = "LEG AVENUE, INC.";
	cout << firstLetterToUpper(name3) << endl; //Leg Avenue, Inc.
	//strlen
	char str[] = "I miss you so much";
	cout << counts(str) << endl; //18
	//index
	char str1[] = "hello world",  sub[] = " ";
	cout << index(str1,sub)<<endl;
	return 0;
}