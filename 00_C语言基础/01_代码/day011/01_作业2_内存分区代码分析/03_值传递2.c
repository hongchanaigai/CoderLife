/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-05 16:59
 * Last modified  : 2020-08-05 17:13
 * Filename       : 03_值传递2.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h> //malloc(),free()

void func(int *tmp)
{
	*tmp = 100;
}

int main()
{
	int *p = NULL;
	p = (int *)malloc(sizeof(int));
	
	func(p); //值传递,形参修改不会影响实参
	printf("*p = %d\n", *p); //ok,*p = 100

	return 0;
}
