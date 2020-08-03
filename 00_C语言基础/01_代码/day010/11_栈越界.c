/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-03 17:21
 * Last modified  : 2020-08-03 17:21
 * Filename       : 11_栈越界.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h> //malloc()

int main()
{
	//语法上没有问题,栈区分配很大的内存,越界,导致段错误
	//int a[10000000000] = {0};
	
	int * p = (int *)malloc(10000000000 * sizeof(int));
	if(p == NULL)
	{
		printf("error!!!!\n");
	}

	return 0;
}
