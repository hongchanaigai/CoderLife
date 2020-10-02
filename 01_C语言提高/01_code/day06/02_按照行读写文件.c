#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),fopen(),perror(),fclose(),fputs(),fgets(),feof()
#include <stdlib.h>	//system()
#include <string.h>

void my_fputs(char* path)
{
	FILE* fp = NULL;

	/*打开文件*/
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fputs: fopen");
		return;
	}

	/*写文件*/
	char* buf[] = { "aaaaa\n", "bbbbbb\n", "ccccccc\n" };
	int n = 3;

	for (int i = 0; i < n; ++i)
	{
		//fputs函数返回值: 成功返回0,失败返回非0
		int re_fputs = fputs(buf[i], fp);
		printf("re_fputs = %d\n", re_fputs);
	}

	/*关闭文件*/
	fclose(fp);
	fp = NULL;
}

void my_fgets(char* path)
{
	FILE* fp = NULL;

	/*打开文件*/
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fgets: fopen");
		return;
	}

	/*读文件*/
	int buf[50] = { 0 };

	while (!feof(fp))	//文件没有结束
	{
		//fgets函数返回值: 成功返回读取的字符串,失败返回NULL
		//把"\n"会读取,以"\n"作为换行的标识
		//fgets()读取完毕后,自动加字符串结束符0
		//sizeof(buf)代表能存放的字符串的最大值,放不下只能放sizeof(buf),不超过就实际大小存放
		char* re_fgets = fgets(buf, sizeof(buf), fp);
		if (re_fgets != NULL)
		{
			printf("re_fgets = %s\n", re_fgets);
		}
	}

	/*关闭文件*/
	fclose(fp);
	fp = NULL;
}

int main(void)
{
	my_fputs("../02.txt");	//写文件
	my_fgets("../02.txt");	//读文件

	printf("\n");
	system("pause");
	return 0;
}