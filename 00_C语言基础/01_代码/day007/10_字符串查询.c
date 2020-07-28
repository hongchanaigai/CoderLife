/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-26 17:38
 * Last modified  : 2020-07-26 18:13
 * Filename       : 10_字符串查询.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>
#include <string.h> //strchr(), strstr()

int main()
{
	char buf[] = "abcdefg";
	//在buf中查询字符cde,如果找到,返回匹配字符串所在位置的地址
	//如果查询失败,返回NULL
	char *p = strstr(buf, "cde");
	if(p == NULL)
	{
		printf("can not find!!!\n");
	}
	else
	{
		printf("p = %s\n", p);
		printf("p[0] = %c\n", p[0]);
	}

	return 0;
}


int main01()
{
	char buf[] = "abcdefg";
	//在buf中查询字符d,如果找到,返回d所在位置的地址
	//如果查询失败,返回NULL
	char *p = strchr(buf, 'd');
	if(p == NULL)
	{
		printf("can not find!!!\n");
	}
	else
	{
		printf("p = %s\n", p);
	}

	return 0;
}
