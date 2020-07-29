/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-26 20:28
 * Last modified  : 2020-07-26 20:28
 * Filename       : 00_homework_简单计算器.c
 * Description    : 利用函数完成加减乘除 
 * *******************************************************/

#include <stdio.h>
#include <string.h> //strcmp()

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int mult(int a, int b)
{
	return a*b;
}

int divi(int a, int b)
{
	return a/b;
}

int main()
{
	char cmd[5] = {0}; //控制计算方式命令
	int a, b;

	while(1)
	{
		printf("please enter cmd(add,sub,mult,divi a b)(add 10 20): ");
		scanf("%s %d %d", cmd, &a, &b);

		if(0 == strcmp(cmd, "add"))
		{
			printf("result = %d\n", add(a, b));
		}
		else if(0 == strcmp(cmd, "sub"))
		{
			printf("result = %d\n", sub(a, b));
		}
		else if(0 == strcmp(cmd, "mult"))
		{
			printf("result = %d\n", mult(a, b));
		}
		else if(0 == strcmp(cmd, "divi"))
		{
			printf("result = %d\n", divi(a, b));
		}
		else
		{
			return 0;
		}
	}

	return 0;
}
