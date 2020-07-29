/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-28 21:53
 * Last modified  : 2020-07-28 21:53
 * Filename       : 10_空指针.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	//1.空指针,给指针变量赋值为NULL
	//2.NULL就是数字0
	int *p = NULL;
	/*
	 int *p;
	 p = NULL;
	*/

	int a = 11;
	p = &a;

	if(p != NULL)
	{
		*p = 100;
	}

	return 0;
}
