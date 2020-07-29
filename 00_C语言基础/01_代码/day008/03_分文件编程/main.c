/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-26 21:46
 * Last modified  : 2020-07-26 21:46
 * Filename       : main.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>
//包含所需头文件,头文件有相应的声明
#include "mystrlen.h"

//加一个函数声明
//int my_strlen(char str[]);

int main()
{
	printf("len = %d\n", my_strlen("0123456789"));

	return 0;
}
