/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-05 16:46
 * Last modified  : 2020-08-05 16:46
 * Filename       : 01_返回data区的地址.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int *func(void)
{
	static int a = 10;
	return &a; //函数调用完毕,a不释放
}

int main()
{
	int *p = NULL;
	p = func();
	*p = 100;
	printf("*p = %d\n", *p);

	return 0;
}
