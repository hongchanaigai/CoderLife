/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-01 16:32
 * Last modified  : 2020-08-01 16:32
 * Filename       : 09_const修饰的字符指针.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main()
{
	char buf[] = "hello";
	char *p1 = buf;
	*p1 = 'a'; //改变指针所指向的内存
	p1 = NULL; //改变指针变量本身

	//const修饰*,指针指向的内存不能修改
	const char *p2 = buf;
	//*p2 = 'a'; //error
	p2 = NULL; //ok

	return 0;
}
