/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-19 20:12
 * Last modified  : 2020-07-19 20:23
 * Filename       : 019_break.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			if(0 == j)
			{
				break;	//跳出的是最近的内循环
			}
			printf("j = %d\n", j);
		}

		if(5 == i)
		{
			break;	//跳出的是 for(i = 0; i < 10; i++) 循环
		}
		printf("i = %d\n", i);
	}

	return 0;
}

int main02(int argc, char *argv[])
{
	int i;
	for(i = 0; i < 10; i++)
	{
		if(5 == i)
		{
			break;	//break跳出当前的内循环
		}
		printf("i = %d\n", i);
	}

	return 0;
}



int main01(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int num = 0;

	for(i = 0; i < 10; ++i)
	{
		for(j = 0; j < 10; ++j)
		{
			num++;
			if(5 == j)
			//if(5 == num)
			{
				break;
			}
			printf("num = %d\n", num);
		}
	}

	//printf("num = %d\n", num);

	return 0;
}
