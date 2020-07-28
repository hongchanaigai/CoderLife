/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 18:30
 * Last modified  : 2020-07-20 18:34
 * Filename       : 09_不初始化的数组值为多少.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a[10];
	int i;

	for(i = 0; i < 10; ++i)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");

	return 0;
}
