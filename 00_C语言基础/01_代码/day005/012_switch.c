/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-19 16:52
 * Last modified  : 2020-07-19 16:52
 * Filename       : 012_switch.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int num;
	printf("please input a number:");
	scanf("%d", &num);

	//1. switch是关键字,switch()后面没有分号
	//2. switch()中()里只能放整型变量或字符型变量
	//3. switch用法类似于电梯模型
	switch(num)
	{
		case 1:
			printf("first floor.\n");
			break;	//必须,跳出switch语句
		case 2:
			printf("second floor.\n");
			break;
		case 3:
			printf("third floor.\n");
			break;
		default:
			printf("other floor.\n");
			break;
	}

	return 0;
}
