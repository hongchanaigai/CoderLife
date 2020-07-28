/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-19 15:56
 * Last modified  : 2020-07-19 17:50
 * Filename       : 010_if_practice.c
 * Description    :判断一个数是个位,十位,百位,千位 
 * *******************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int num;
	printf("please input a number:");
	scanf("%d", &num);

	if(num < 10)
	{
		printf("bits\n");
	}
	else if(num < 100)
	{
		printf("ten\n");
	}
	else if(num < 1000)
	{
		printf("hundred\n");
	}
	else if(num < 10000)
	{
		printf("thousand\n");
	}
	else
	{
		printf("others\n");
	}

	return 0;
}


int main01(int argc, char *argv[])
{
	int num;
	printf("please input a number:");
	scanf("%d", &num);

	if(0 < num && num < 10)
	{
		printf("bits\n");
	}
	else if(9 < num && num < 100)
	{
		printf("ten\n");
	}
	else if(99 < num && num < 1000)
	{
		printf("hundred\n");
	}
	else if(999 < num && num < 10000)
	{
		printf("thousand\n");
	}
	else
	{
		printf("others\n");
	}

	return 0;
}
