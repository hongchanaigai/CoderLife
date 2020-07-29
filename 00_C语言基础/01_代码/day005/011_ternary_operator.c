/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-19 16:34
 * Last modified  : 2020-07-19 16:41
 * Filename       : 011_ternary_operator.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	//三目运算符,就是简洁版if else
	int a = 10;
	int b = 20;
	int c;

	if(a > b)
	{
		c = a;
	}
	else
	{
		c = b;
	}

	printf("the max is : %d\n", c);

	a = 100;
	b = 200;
	//1. ?:(三目运算符)优先级比=高
	//2. 判断a > b条件,如果为真,执行?:之间的语句
	//		   如果为假,执行:;之间的语句
	c = a > b ? a : b;
	printf("second : the max is : %d\n", c);

	return 0;
}
