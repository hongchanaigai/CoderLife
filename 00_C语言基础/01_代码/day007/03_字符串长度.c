/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-25 18:39
 * Last modified  : 2020-07-25 18:47
 * Filename       : 03_字符串长度.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>
#include <string.h> //strlen()

int main()
{
	char buf[] = "hello";

	//strlen()需要使用返回值,返回值就是字符串长度
	//从首元素开始,到结束符为止的长度,结束符不算(遇到'\0'结束)
	int len  = strlen(buf);
	printf("len = %d\n", len);
	printf("sizeof(buf) = %lu\n", sizeof(buf)); //多了一个结束符'\0'

	char buf1[] = "\0hello";
	len = strlen(buf1);
	printf("len1 = %d\n", len);
	//sizeof()测数据类型的长度,不会因为结束符提前结束
	printf("sizeof(buf1) = %lu\n", sizeof(buf1)); //多了一个结束符'\0'

	char str[100] = "mike";
	printf("strlen(str) = %lu\n", strlen(str)); //4
	printf("sizeof(str) = %lu\n", sizeof(str)); //100

	return 0;
}
