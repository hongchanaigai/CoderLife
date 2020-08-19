/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-18 18:12
 * Last modified  : 2020-08-18 18:43
 * Filename       : 01_二级指针做形参.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

void fun(int **tmp)
{
	int *p = (int *)malloc(sizeof(int));
	*p = 10;

	 *tmp = p;
}

int main()
{
	int *p = NULL;
	fun(&p); //在fun函数内部动态分配空间

	printf("*p = %d\n", *p);

	if(p != NULL);
	{
		free(p);
		p = NULL;
	}

	return 0;
}
