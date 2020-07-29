/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-25 17:46
 * Last modified  : 2020-07-25 18:26
 * Filename       : 01_字符串输入.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

//1. scanf()的使用
int main00()
{
	char buf[100] = {0};
	printf("please enter a string: ");
	scanf("%s", buf); //不需要&, 默认以空格分开
	printf("buf = %s\n", buf);

	char buf1[100] = {0};
	printf("please enter a string: ");
	scanf("%s", buf1); //不需要&, 默认以空格分开
	printf("buf1 = %s\n", buf1);

	//scanf()的缺陷,不做越界检查,此函数不安全
	char str[10];
	printf("please enter a string: ");
	scanf("%s", str); //不需要&, 默认以空格分开
	printf("str = %s\n", str);

	return 0;
}

int main01()
{
	char buf[100];
	//gets()从键盘读取字符串,放在指定的数组
	//gets()允许有空格,不做越界检查,此函数不安全
	gets(buf);
	printf("buf = %s\n", buf);

	return 0;
}


int main()
{
	char buf[10];
	//从stdin(代表标准输入,键盘),读取内容
	//如果输入内容大于sizeof(buf) - 1,只读取sizeof(buf) - 1,放在buf所在的数组
	//会把换行符也读进去
	fgets(buf, sizeof(buf), stdin);
	printf("buf = %s\n", buf);

	return 0;
}
