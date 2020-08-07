/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 17:33
 * Last modified  : 2020-08-07 17:33
 * Filename       : 03_打开文件.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main()
{
	FILE *fp = NULL;

	//打开成功,返回有效地址
	//打开失败,返回NULL
	//"w",如果文件不存在,新建,如果存在,清空内容再打开
	//"r",如果文件不存在,打开失败
	//"a",如果文件不存在,新建,如果存在,光标自动放在文件末尾
	fp = fopen("./03.txt", "r");
	if(fp == NULL)
	{
		perror("fopen");
		return 0;
	}

	fclose(fp);
	fp = NULL;

	return 0;
}
