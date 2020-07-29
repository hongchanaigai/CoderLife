/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-26 20:54
 * Last modified  : 2020-07-26 20:54
 * Filename       : 01_exit和return区别.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>
#include <stdlib.h> //exit()

void func()
{
	//return;
	printf("func\n");
	//return;
	exit(1); //结束整个程序,结束进程
}

int main()
{
	func();

	//return 0; //return作用:中断函数,中断main(),程序就结束
	printf("main\n");

	return 0;
}
