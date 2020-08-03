/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-02 20:21
 * Last modified  : 2020-08-02 20:21
 * Filename       : 05_C语言全局变量的缺陷.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int a;
int a;
int a = 0; //定义,其他是声明
int a;
int a;

//有1次是定义,有3次声明
int b;
int b;
int b;
int b;

//1. 如果定义一个全局变量,没有赋值(初始化),无法确定是定义,还是声明
//2. 如果定义一个全局变量,同时初始化,这个肯定是定义

int main()
{
	//只有声明,没有定义,无法给变量赋值
	//extern int b = 10;
	
	b = 10;
	printf("b = %d\n", b);

	return 0;
}
