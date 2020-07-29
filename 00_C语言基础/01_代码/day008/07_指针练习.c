/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-28 20:41
 * Last modified  : 2020-07-28 20:41
 * Filename       : 07_指针练习.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a = 10;
	int *p;
	p = &a;

	int b = *p;

	*p = 111;
	printf("a = %d, b = %d\n", a, b);

	return 0;
}
