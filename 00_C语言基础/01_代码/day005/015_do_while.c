/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-19 17:49
 * Last modified  : 2020-07-19 17:52
 * Filename       : 015_do_while.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 1;
	int sum = 0;

	//1. do while第一次无条件执行
	//2. 第二次开始,和while一样
	do
	{
		sum += i;
		i++;
	}while(i <= 100); //注意,这里有分号,这是语法

	printf("1 + 2 + 3 + ... + 100 = %d\n", sum);

	return 0;
}
