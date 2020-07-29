/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-29 18:44
 * Last modified  : 2020-07-29 18:44
 * Filename       : 23_作业2_实现字符串拷贝功能.c
 * Description    : 不使用库函数,实现字符串拷贝功能
 * *******************************************************/

#include <stdio.h>

int main()
{
	char src[100] = "hello";
	char dst[100];
	char * p = src; //指向src数组的首元素
	char * q = dst; //指向dst数组的首元素

	while(*p != '\0')
	{
		*q = *p;
		++p;
		++q;
	}

	printf("src = %s\n", src);
	printf("dst = %s\n", dst);

	return 0;
}
