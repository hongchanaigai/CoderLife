/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-30 18:50
 * Last modified  : 2020-07-30 18:50
 * Filename       : 03_返回值是指针类型.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int *func()
{
	int a;

	return &a;
}

int main()
{
	int *p = NULL;

	p = func(); //接收函数返回的地址
	*p = 100; //操作指针所指向的内存

	return 0;
}
