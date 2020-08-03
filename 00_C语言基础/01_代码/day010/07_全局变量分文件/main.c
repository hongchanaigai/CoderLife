/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-02 20:53
 * Last modified  : 2020-08-02 20:53
 * Filename       : main.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include "test.h" //头文件方式

int main()
{
	test();

	a = 111;
	b = 222;

	return 0;
}

int main01()
{
	//使用函数前,声明函数
	//声明函数,extern可有可无
	extern void test();

	test(); //函数调用

	//使用全局变量前,先声明
	extern int a;
	extern int b;

	a = 111;
	b = 222;

	return 0;
}
