/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-28 21:39
 * Last modified  : 2020-07-28 21:39
 * Filename       : 09_野指针2.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a = 10;
	int *p;
	*p = &a;

	int b = *p;

	*p = 111;
	printf("a = %d, b = %d\n", a, b);

	return 0;
}
