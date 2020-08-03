/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-02 16:54
 * Last modified  : 2020-08-02 16:54
 * Filename       : 00_作业1_my_atoi.c
 * Description    : 不使用库函数,编写一个my_atoi(),功能和atoi()一样
 * *******************************************************/
#include <stdio.h>

int my_atoi(char *str)
{
	char *tmp = str;
	int flag = 0; //0代表正数,1代表负数

	//判断正负数
	if(*tmp == '-')
	{
		flag = 1; //设置为负数
		tmp += 1; //从第二个字符开始转化
	}
	else if(*tmp == '+')
	{
		//flag = 0; //默认初始化的flag = 0,为正数
		tmp += 1; //从第二个字符开始
	}

	//转化
	int num = 0;
	while(*tmp != '\0') //到结束符停止
	{
		num = num * 10 + (*tmp - '0'); //字符转数字方法'1'-'0' = 1
		++tmp; //下一个字符
	}

	//输出
	if(0 == flag)
	{
		return num;
	}
	else if(1 == flag)
	{
		return -num;
	}
}

int main()
{
	printf("+123 = %d\n", my_atoi("+123")); //十进制123
	printf("-123 = %d\n", my_atoi("-123")); //十进制-123
	printf("123 = %d\n", my_atoi("123")); //十进制123

	return 0;
}
