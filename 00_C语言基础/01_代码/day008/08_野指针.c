/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-28 21:23
 * Last modified  : 2020-07-28 21:23
 * Filename       : 08_野指针.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int *p;

	p = 0x1234;
	printf("p = %d\n", p);

	*p = 100;

	return 0;
}
