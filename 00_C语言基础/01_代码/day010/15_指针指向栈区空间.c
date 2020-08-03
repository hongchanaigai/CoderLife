/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-03 18:23
 * Last modified  : 2020-08-03 18:23
 * Filename       : 15_指针指向栈区空间.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main()
{
	int *p;
	int a; //定义一个栈区变量
	p = &a;//指针指向栈区空间
	
	*p = 10;
	printf("*p = %d\n", *p);

	return 0;
}
