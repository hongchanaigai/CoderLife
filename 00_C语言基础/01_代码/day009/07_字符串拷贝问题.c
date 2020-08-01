/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-30 21:06
 * Last modified  : 2020-07-30 21:06
 * Filename       : 07_字符串拷贝问题.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //strcpy()

int main()
{
	char buf[100];
	char *p = buf;
	//1. p指向buf的首元素
	//2. strcpy()是给p所指向的内存拷贝内容,字符拷贝给了buf
	strcpy(p, "hello huang abc");

	printf("p = %s, buf = %s\n", p, buf);

	return 0;
}

int main01()
{
	char *p;
	//1. 不是给p变量拷贝内容
	//2. 给p所指向的内存拷贝内容
	//3. p是野指针,给野指针所指向的内存拷贝内容,结果导致段错误
	strcpy(p, "hello huang abc"); //error,段错误

	return 0;
}
