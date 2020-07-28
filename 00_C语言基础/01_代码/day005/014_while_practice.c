/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-19 17:19
 * Last modified  : 2020-07-19 17:33
 * Filename       : 014_while_practice.c
 * Description    :通过while实现1+2+3+...+100 
 * *******************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int num = 1;
	int sum = 0;

	while(num <= 100)
	{
		sum += num;
		num++;
	}

	/*
	 1. i = 1,满足i <= 100,执行{}语句
	 	sum = 0 + 1
		i = 2

	 2. i = 2,满足i <= 100,执行{}语句
	 	sum = 0 + 1 + 2
		i = 3

	 3. i = 3,满足i <= 100,执行{}语句
		sum = 0 + 1 + 2 + 3
		i = 4	
	 */

	printf("1 + 2 + 3 + ... + 100 = %d\n", sum);

	return 0;
}
