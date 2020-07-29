/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-19 15:41
 * Last modified  : 2020-07-19 15:41
 * Filename       : 009_if_else_if.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 4;

	if(3 == a)
	{
		printf("3 == a\n");
	}
	else if(a > 3)
	{
		printf("a > 3\n");
	}
	else if(a < 3)
	{
		printf("a < 3\n");
	}
	else	//else不是必须的
	{
		printf("it is impossiable.\n");
	}

	return 0;
}



int main01(int argc, char *argv[])
{
	int a = 3;

	if(3 == a) //如果a和3相等,执行语句
	{
		printf("a == 3\n");
	}
	//1.if else结构,这个else可以不写,else不是必须的
	//2.else后面不要接条件
	else
	{
		printf("3 != a\n");
	}

	return 0;
}
