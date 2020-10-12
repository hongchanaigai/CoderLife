/*
3. 文件拷贝程序，例子参考《03_拷贝文件》
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),scanf(),perror(),exit(),fopen(),fclose(),fread(),fwrite()
#include <stdlib.h>	//system()
#include <string.h>	//strcmp()

#define SIZE 1024*2	//每次写入2k的数据

/// <summary>
/// 输出菜单
/// </summary>
void menu()
{
	printf("\n*********************************");
	printf("\n\t1. copy a file");
	printf("\n\t2. clear the screen");
	printf("\n\t3. exit");
	printf("\n*********************************");
}

/// <summary>
/// 拷贝一个文件
/// </summary>
void myCopy()
{
	char src_path[256] = { 0 };	//源文件文件路径
	char dst_path[256] = { 0 };	//目的文件文件路径
	int ret = 0;	//函数返回值,检查函数调用是否出错

	FILE* src_fp = NULL;	//源文件文件指针
	FILE* dst_fp = NULL;	//目的文件文件指针
	char buf[SIZE] = { 0 };	//拷贝文件时的临时内存
	int n = 0;

	/*提示输入文件*/

	//提示输入源文件
	printf("\nplease input the source file: ");
	ret = scanf("%s", src_path);
	if (ret == -1)
	{
		perror("myCopy: scanf error(src_path)");
		return;
	}

	//提示输入目的文件
	printf("\nplease input the destination file: ");
	ret = scanf("%s", dst_path);
	if (ret == -1)
	{
		perror("myCopy: scanf error(dst_path)");
		return;
	}

	//提示源文件和目的文件不能相同
	ret = strcmp(src_path, dst_path);
	if (0 == ret)
	{
		printf("\nthe source and destination files can not be the same");
		return;
	}

	/*打开文件*/

	//以只读的方式打开源文件(2进制)
	src_fp = fopen(src_path, "rb");
	if (src_fp == NULL)
	{
		perror("myCopy: fopen error(scr_fp)");
		return;
	}

	//以只写的方式打开目的文件(2进制)
	dst_fp = fopen(dst_path, "wb");
	if (dst_fp == NULL)
	{
		perror("myCopy: fopen error(dst_fp)");
		//此时源文件已经打开,需要关闭
		goto CloseSrcFile;
		return;
	}

	/*读写文件*/

	//开始拷贝文件,读多少写多少
	do
	{
		n = 0;	//每次循环都要置0
		//读多少写多少
		n = fread(buf, sizeof(char), SIZE, src_fp);
		printf("\ncopy: %d", n);

		ret = fwrite(buf, sizeof(char), n, dst_fp);
		if (ret != n)
		{
			perror("myCopy: fwrite error");
			//此时源文件,目的文集N已经打开,需要关闭
			goto CloseSrcFile;
			goto CloseDstFile;
			return;
		}

	} while (n > 0);

	printf("\nthe file copy is complete");

	/*关闭文件*/

	//关闭源文件
CloseSrcFile:
	if (src_fp != NULL)
	{
		fclose(src_fp);
		src_fp == NULL;
	}

	//关闭目的文件
CloseDstFile:
	if (dst_fp != NULL)
	{
		fclose(dst_fp);
		dst_fp == NULL;
	}
}

int main(void)
{
	int cmd = 0;	//用户输入的命令
	int ret = 0;	//函数返回值,检验函数调用是否出错
	
	while (1)
	{
		menu();	//输出菜单

		printf("\nplease input a command: ");
		ret = scanf("%d", &cmd);
		if (ret == -1)
		{//scanf()函数调用出错
			perror("main: scanf error");
			return -1;
		}

		switch (cmd)
		{
		case 1:
			//拷贝文件
			myCopy();
			break;
		case 2:
			//清屏
			system("cls");
			break;
		default:
			//退出程序
			exit(0);
		}
	}

	printf("\n");
	system("pause");
	return 0;
}