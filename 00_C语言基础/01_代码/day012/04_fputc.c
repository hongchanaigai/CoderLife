/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 18:14
 * Last modified  : 2020-08-07 18:14
 * Filename       : 04_fputc.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main()
{
	//1. 打开文件
	FILE *fp = NULL;
	//以写方式打开文件,如果文件不存在,自动创建
	fp = fopen("./04.txt", "w");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}

	//2. 写文件fputc(),一次只能写一个字符
	fputc(97, fp);

	//3. 关闭文件
	fclose(fp);
	fp = NULL;

	return 0;
}

int main01()
{
	//1. 打开文件
	FILE *fp = NULL;
	//以写方式打开文件,如果文件不存在,自动创建
	fp = fopen("./04.txt", "w");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}

	//2. 写文件fputc(),一次只能写一个字符
	char ch = 'a';
	while(ch <= 'z')
	{
		fputc(ch, fp);
		++ch;
	}

	//3. 关闭文件
	fclose(fp);
	fp = NULL;

	return 0;
}

int main00()
{
	//1. 打开文件
	FILE *fp = NULL;
	//以写方式打开文件,如果文件不存在,自动创建
	fp = fopen("./04.txt", "w");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}
	//2. 写文件fputc(),一次只能写一个字符
	//fputc("a", fp);
	//fputc("b", fp);
	//fputc("c", fp);
	//fputc("d", fp);
	
	fputc("a", stdout);
	fputc("b", stdout);
	fputc("c", stdout);
	fputc("d", stdout);

	//3. 关闭文件
	fclose(fp);
	fp = NULL;

	return 0;
}
