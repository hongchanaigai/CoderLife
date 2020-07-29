/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-19 20:12
 * Last modified  : 2020-07-19 20:20
 * Filename       : 018_循环嵌套.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int num = 0;

	for(i = 0; i < 10; ++i)
	{
		for(j = 0; j < 10; ++j)
		{
			num++;
		}
	}

	printf("num = %d\n", num);

	return 0;
}
