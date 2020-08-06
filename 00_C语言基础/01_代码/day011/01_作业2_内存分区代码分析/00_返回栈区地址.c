/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-05 16:41
 * Last modified  : 2020-08-05 16:41
 * Filename       : 00_返回栈区地址.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int *func(void)
{
	int a = 10;
	return &a; //函数调用完毕,a释放
}

int main()
{
	int *p = NULL;
	p = func();
	*p = 100; //error,操作野指针指向的内存

	return 0;
}
