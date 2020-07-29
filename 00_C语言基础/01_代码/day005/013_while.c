/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-19 17:08
 * Last modified  : 2020-07-19 17:08
 * Filename       : 013_while.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int num = 1;

	//1. 判断num > 0的条件,如果为真,执行{}语句
	//		       如果为假,跳出while()循环
	//2. 执行完{}语句,重复1步骤
	while(num > 0)	//这里没有分号
	{
		printf("please input a number(negative number exit while): ");
		scanf("%d", &num);
	} //这里也没有分号

	return 0;
}
