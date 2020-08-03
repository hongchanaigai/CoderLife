/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-03 16:48
 * Last modified  : 2020-08-03 16:48
 * Filename       : 10_test.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int a; //未初始化
int c;
int d;

void func()
{
	static int b = 10; //初始化
}

int main()
{

	return 0;
}
