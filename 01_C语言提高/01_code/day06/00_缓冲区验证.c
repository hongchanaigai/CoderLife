#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),fopen(),fputs(),fclose(),fflush()
#include <stdlib.h>	//system()
#include <string.h>

int main(void)
{
	/*
	操作文件,是先把数据放到缓冲区,程序结束/文件关闭/刷新缓冲区,才会把数据写入文件
	除非缓冲区满了,才会写入
	*/
	char buf[] = "this is a 00_test.\n";
	
	//打开文件
	FILE* fp = fopen("./00_test.txt", "w+");
	//写文件
	fputs(buf, fp);
	//刷新缓冲区
	fflush(fp);
	//关闭文件
	fclose(fp);

	printf("\n");
	system("pause");
	return 0;
}