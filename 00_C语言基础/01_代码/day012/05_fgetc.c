/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 18:57
 * Last modified  : 2020-08-07 18:57
 * Filename       : 05_fgetc.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

void write_file()
{
	//1. 打开文件
	FILE *fp = fopen("5.txt", "w");
	if(fp ==NULL)
	{
		perror("write_file fopen");
		return;
	}
	//2. 写文件
	char ch = 'a';
	while(ch <= 'z')
	{
		fputc(ch, fp);
		++ch;
	}
	//3. 关闭文件
	fclose(fp);
	fp = NULL;
}

void read_file()
{
	//1. 打开文件
	FILE *fp = fopen("5.txt", "r");
	if(fp ==NULL)
	{
		perror("read_file fopen");
		return;
	}
	//2. 读文件,每次打开一个字符
	char ch;
	while(1)
	{
		ch = fgetc(fp);
		if(EOF == ch)
		{
			break;
		}
		printf("ch = %c\n", ch);
	}
	//3. 关闭文件
	fclose(fp);
	fp = NULL;
}

int main()
{
	write_file();

	read_file();

	return 0;
}
