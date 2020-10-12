/*
1. 将一个未知大小的文件(如: song.txt )全部读入(不是一行一行读取)内存，
	并显示在屏幕上，例子参考《01_ReadSong》

	参考：fseek(),  ftell(),  rewind(),  fread(),  malloc()
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),fopen(),perror(),fclose(),fseek(),ftell(),fread()
#include <stdlib.h>	//system()
#include <string.h>	//malloc(),free()

/// <summary>
/// 将一个未知大小的文件(如: song.txt )全部读入(不是一行一行读取)内存，并显示在屏幕上
/// </summary>
/// <param name="path">文件路径</param>
void readSong(char* path)
{
	if (path == NULL)
	{
		printf("readSong error: path == NULL\n");
		return;
	}

	FILE* fp = NULL;	//文件指针
	int ret = 0;	//调用的函数返回值,判断函数调用是否出错
	long size = 0;	//保存文件大小
	char* buf = NULL;	//用来动态分配内存
	
	/*以读(二进制)方式打开文件*/
	fp = fopen(path, "rb");
	
	//出错判断,打开文件失败,结束程序
	if (fp == NULL)
	{
		perror("readSong: fopen error");
		return;
	}

	/*
	读文件
	1. 获取文件大小
	2. 分配合适的内存
	3. 按块读文件
	4. 释放内存
	*/

	/*1. 获取文件大小*/

	//光标移动到文件结尾
	ret = fseek(fp, 0, SEEK_END);
	if (ret != 0)
	{
		perror("readSong: fseek1 error");
		goto CloseFile;	//此时文件已经打开,先关闭再结束程序
		return;
	}
	
	//读取文件大小
	size = ftell(fp);
	if (size == -1)
	{
		perror("readSong: ftell error");
		goto CloseFile;	//此时文件已经打开,先关闭再结束程序
		return;
	}

	//光标移动到文件开头
	ret = fseek(fp, 0, SEEK_SET);
	if (ret != 0)
	{
		perror("readSong: fseek2 error");
		goto CloseFile;	//此时文件已经打开,先关闭再结束程序
		return;
	}

	/*2. 分配合适的内存*/
	if (size == 0)
	{//文件大小为0
		printf("the file size is 0\n");
	}
	else
	{//文件大小不为0,开始分配合适大小的内存
		buf = (char*)malloc(size * sizeof(char) + 1);
		if (buf == NULL)
		{//分配内存失败,退出程序
			perror("readSong: malloc error");
			goto CloseFile;	//此时文件已经打开,先关闭再结束程序
			return;
		}
	}

	/*3. 按块读文件*/
	ret = fread(buf, size, 1, fp);
	if (ret != 1)
	{//读取文件失败
		perror("readSong: fread error");
		goto FreeBuf;	//此时内存已经分配,先释放再结束程序
		goto CloseFile;	//此时文件已经打开,先关闭再结束程序
		return;
	}

	//读取成功,结尾添加字符串结束符
	if (buf != NULL)
	{
		buf[size] = '\0';
	}

	//输出
	if (buf != NULL && ret == 1)
	{
		printf("%s\n", buf);
	}

	/*4. 释放内存*/
FreeBuf:
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}

	/*关闭文件*/
CloseFile:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main(void)
{
	readSong("./song.txt");

	printf("\n");
	system("pause");
	return 0;
}