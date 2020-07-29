/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 17:47
 * Last modified  : 2020-07-20 17:47
 * Filename       : 07_数组元素的使用.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a[10];

	int i = 0;
	for(i = 0; i < 10; ++i)
	{
		a[i] = i + 1;
	}

	for(i = 0; i < 10; ++i)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");

	return 0;
}
