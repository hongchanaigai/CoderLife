/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-28 22:38
 * Last modified  : 2020-07-28 22:38
 * Filename       : 13_多级指针2.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int **************p;
	p = 0x1122;
	int *****************q;
	q = &p;
	
	*q = 0xaabb;
	printf("p = %x\n", p);

	*p = 0xbbcc;

	return 0;
}
