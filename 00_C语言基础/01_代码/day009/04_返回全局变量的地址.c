/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-30 19:21
 * Last modified  : 2020-07-30 19:21
 * Filename       : 04_返回全局变量的地址.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

//1. 在{}外面定义的变量,就是全局变量,全局变量任何地方都能用
//2. 全局变量只有在整个程序结束后,才释放
int a;

int *func()
{
	return &a; //func()调用完毕,a不释放
}

int main()
{
	int *p = NULL;
	p = func();

	*p = 100;
	printf("*p = %d\n", *p);
	printf("a = %d\n", a);

	*( func() ) = 111;
	printf("a = %d\n", a);

	return 0;
}
