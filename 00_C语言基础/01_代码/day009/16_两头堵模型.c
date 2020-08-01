/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-01 20:16
 * Last modified  : 2020-08-01 20:16
 * Filename       : 16_两头堵模型.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //strlen(), strncpy()

int main()
{
	char *p = "       123456789           ";
	char *start = p; //首元素地址
	char *end = p + strlen(p) - 1; //尾元素地址

	//从左往右
	while(*start == ' ' && *start != '\0')
	{
		++start;
	}

	//从右往左
	while(*end == ' ' && end != p)
	{
		--end;
	}

	int n = end - start + 1;
	printf("n = %d\n", n);

	char buf[100];
	strncpy(buf, start, n);
	buf[n] = '\0'; //结束符
	printf("buf = %s\n", buf);

	return 0;
}
