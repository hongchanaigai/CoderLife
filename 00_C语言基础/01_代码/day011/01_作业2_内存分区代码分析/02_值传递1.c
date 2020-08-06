/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-05 16:59
 * Last modified  : 2020-08-05 16:59
 * Filename       : 02_值传递1.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h> //malloc(),free()

void func(int *tmp)
{
	tmp = (int *)malloc(sizeof(int));
	*tmp = 100;
	free(tmp);
}

int main()
{
	int *p = NULL;
	func(p); //值传递,形参修改不会影响实参
	printf("*p = %d\n", *p); //error,操作空指针指向的内存

	return 0;
}
