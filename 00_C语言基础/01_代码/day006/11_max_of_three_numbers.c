/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 19:05
 * Last modified  : 2020-07-20 19:10
 * Filename       : 11_max_of_three_numbers.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;

	int max = a;
	
	if(b > max)
	{
		max = b;
	}

	if(c > max)
	{
		max = c;
	}

	printf("max = %d\n", max);

	return 0;
}


int main01()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int max;

	max = a > b ? a : b;
	printf("max = %d\n", max);

	max = (a>b?a:b) > c ? (a>b?a:b) : c;
	printf("max = %d\n", max);

	return 0;	
}


int main00()
{
	int a = 10;
	int b = 20;
	int c = 30;

	int max;

	if(a > b)
	{
		max = a;
	}
	else
	{
		max = b;
	}

	if(max > c)
	{
		printf("the max number is %d.\n", max);
	}
	else
	{
		printf("the max number is %d.\n", c);
	}

	return 0;
}
