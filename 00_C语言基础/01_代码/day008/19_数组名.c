/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-29 17:36
 * Last modified  : 2020-07-29 17:36
 * Filename       : 19_数组名.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a[10];
	//1. 数组名是数组首元素地址
	printf("a = %p, &a[0] = %p\n", a, &a[0]);

	//2. 数组名是常量,不允许修改,int * const p;
	//a = 10; //error
	
	return 0;
}
