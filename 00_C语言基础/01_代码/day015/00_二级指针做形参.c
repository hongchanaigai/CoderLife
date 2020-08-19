/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-18 18:12
 * Last modified  : 2020-08-18 18:12
 * Filename       : 00_二级指针做形参.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

void fun(int **tmp)
{
	*tmp = (int *)malloc(sizeof(int));
	**tmp = 100;
}

int main()
{
	int *p = NULL;
	fun(&p); //在fun函数内部动态分配空间

	printf("*p = %d\n", *p);

	return 0;
}
