/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 18:57
 * Last modified  : 2020-08-07 19:17
 * Filename       : 06_fgetc.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

void write_file()
{
	//1. 打开文件
	FILE *fp = fopen("6.txt", "w");
	if(fp ==NULL)
	{
		perror("write_file fopen");
		return;
	}
	//2. 写文件
	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);
	fputc(-1, fp);
	fputc('d', fp);
	fputc(-1, fp);
	fputc('e', fp);
	//3. 关闭文件
	fclose(fp);
	fp = NULL;
}

void read_file()
{
	//1. 打开文件
	FILE *fp = fopen("6.txt", "r");
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
		if(feof(fp)) //如果到文件结尾,返回真
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
