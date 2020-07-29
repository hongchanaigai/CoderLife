/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-28 20:20
 * Last modified  : 2020-07-28 20:20
 * Filename       : 06_同类型的指针变量赋值.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a = 0;
	int *p = &a;

	*p = 111;

	int *q;
	q = p;
	*q = 222;
	printf("&a = %p, p = %p, q = %p\n", &a, p, q);

	printf("a = %d, *p = %d, *q = %d\n", a, *p, *q);
}
