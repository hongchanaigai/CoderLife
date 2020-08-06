/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-05 17:20
 * Last modified  : 2020-08-05 17:20
 * Filename       : 04_返回堆区地址.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h> //malloc(),free()

int *func()
{
	int *tmp = NULL;
	tmp = (int *)malloc(sizeof(int));
	*tmp = 100;
	return tmp; //返回堆区地址,函数调用完毕,不释放
}

int main()
{
	int *p = NULL;
	p = func();
	printf("*p = %d\n", *p); //ok

	//堆区空间,使用完毕,手动释放
	if(p != NULL)
	{
		free(p);
		p = NULL;
	}

	return 0;
}
