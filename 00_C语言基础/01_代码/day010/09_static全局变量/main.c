/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-02 21:53
 * Last modified  : 2020-08-02 21:53
 * Filename       : main.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

//int a = 0; //error,重复定义,test.c中也有

static int b = 0; //ok

int main()
{
	extern int a;
	a = 11;

	return 0;
}
