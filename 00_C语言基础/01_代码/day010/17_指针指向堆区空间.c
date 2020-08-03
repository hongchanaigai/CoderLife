/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-03 18:31
 * Last modified  : 2020-08-03 19:04
 * Filename       : 17_指针指向堆区空间.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h> //malloc(),free()

int main()
{
	int *p;

	p = (int *)malloc(sizeof(int)); //申请分配空间
	if(NULL == p)
	{
		printf("malloc error!!!\n");
		return -1;
	}

	*p = 10;
	printf("*p = %d\n", *p);

	if(NULL != p)
	{
		free(p); //使用完手动释放分配空间
		p = NULL; //这一步很重要
	}//解决重复释放,发生段错误问题

	//*p = 11; //error,野指针
	//printf("*p = %d\n", *p);
	
	return 0;
}
