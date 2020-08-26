/*
2. 有一个字符串开头或结尾含有n个空格 （”   abcdefgdddd    ”），欲去掉前后空格，返回一个新字符串。
	要求1：请自己定义一个接口（函数），并实现功能；
	要求2：编写测试用例。
	int trimSpace(char *inbuf, char *outbuf);
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>	//strlen(),strncpy()
#include <ctype.h>	//isspace()

int trimSpace(char* inbuf, char* outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}

	char* tmp_inbuf = inbuf;	//辅助变量,不直接使用形参
	int begin = 0;	//字符串首元素下标
	int end = strlen(tmp_inbuf) - 1;	//字符串尾元素下标

	//从首元素开始向右走
	while (isspace(tmp_inbuf[begin]) && tmp_inbuf[begin] != '\0')
	{
		begin++;
	}

	//从尾元素开始向左走
	while (isspace(tmp_inbuf[end]) && tmp_inbuf[end] != '\0')
	{
		end--;
	}

	int n = end - begin + 1;

	strncpy(outbuf, tmp_inbuf + begin, n);
	outbuf[n] = '\0';	

	return 0;
}

int main(void)
{
	char* inbuf = "   abcdefgdddd    ";
	char outbuf[100] = { 0 };
	int ret = 0;

	ret = trimSpace(inbuf, outbuf);
	if (ret != 0)
	{
		printf("trimSpace error!!!\n");
		return ret;
	}

	printf("inbuf = %s\n", inbuf);
	printf("outbuf = %s\n", outbuf);

	printf("\n");
	system("pause");
	return 0;
}