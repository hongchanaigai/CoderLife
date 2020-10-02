#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),fopen(),fclose(),fprintf(),fscanf()
#include <stdlib.h>	//system()
#include <string.h>

void my_fprintf(char* path)
{
	if (path == NULL)
	{
		printf("my_fprintf: input error: path == NULL\n");
		return;
	}

	FILE* fp = NULL;

	/*打开文件*/
	fp = fopen("../04.txt", "w+");
	if (fp == NULL)
	{
		perror("my_fprintf: fopen");
		return;
	}

	/*按照格式化方式写文件*/
	/*printf("hello,this is my_fprintf: printf %d\n", 111);
	fprintf(stdout, "hello,this is my_fprintf: fprintf(sdtout) %d\n", 222);*/
	fprintf(fp, "hello,this is my_fprintf: fprintf(04.txt) %d\n", 333);

	/*关闭文件*/
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fscanf(char* path)
{
	if (path == NULL)
	{
		printf("my_fscanf: input error: path == NULL\n");
		return;
	}

	FILE* fp = NULL;

	/*打开文件*/
	fp = fopen("../04.txt", "r+");
	if (fp == NULL)
	{
		perror("my_fscanf: fopen error");
		return;
	}

	/*按照格式化方式读文件*/
	int i = 0;
	
	int re_fscanf = fscanf(fp, "hello,this is my_fprintf: fprintf(04.txt) %d\n", &i);
	if (re_fscanf == -1)
	{
		perror("my_fscanf: fscanf error");
		return;
	}
	printf("fscanf: i = %d\n", i);

	/*关闭文件*/
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main(void)
{
	my_fprintf("../04.txt");
	my_fscanf("../04.txt");

	printf("\n");
	system("pause");
	return 0;
}