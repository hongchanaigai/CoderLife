/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 19:57
 * Last modified  : 2020-08-07 19:57
 * Filename       : 08_mycat.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
	//打开文件,文件路径,argv[1]
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		perror("fopen");
		return 0;
	}

	//读文件内容,将内容显示在屏幕
	char ch;
	while(1)
	{
		ch = fgetc(fp);
		if(feof(fp)) //到文件结尾,退出循环
		{
			break;
		}
		printf("%c", ch);
	}

	//关闭文件
	fclose(fp);
	fp = NULL;

	return 0;
}
