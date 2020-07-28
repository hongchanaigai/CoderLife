/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-19 20:55
 * Last modified  : 2020-07-19 20:59
 * Filename       : 020_continue.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int i;

	for(i = 0; i < 10; i++)
	{
		if(5 == i)
		{
			//break;	//跳出整个循环,不再执行循环
			continue;	//跳出本次循环,下次继续
		}
		printf("i = %d\n", i);
	}

	return 0;
}
