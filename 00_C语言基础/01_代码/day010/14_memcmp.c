/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-03 18:16
 * Last modified  : 2020-08-03 18:16
 * Filename       : 14_memcmp.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //memcmp()

int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
	int flag = memcmp(a, b, 10*sizeof(int));
	if(flag < 0)
	{
		printf("a < b\n");
	}
	else if(flag > 0)
	{
		printf("a > b\n");
	}
	else
	{
		printf("a = b\n");
	}

	return 0;
}
