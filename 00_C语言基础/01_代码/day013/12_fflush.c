/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-09 18:38
 * Last modified  : 2020-08-09 18:38
 * Filename       : 12_fflush.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main()
{
	FILE *fp = fopen("12.txt", "w");

	fputs("this is the last day!!!\n", fp);

	//1. 默认情况,程序没有结束,也没有关闭文件,缓冲区满,自动刷新缓冲区
	
	//2. 文件正常关闭,缓冲区的内容也会写入文件
	//fclose(fp);
	
	//3. 文件不关闭,程序没有结束,实时刷新缓冲区,调用fflush()
	//fflush(fp);
	
	//4. 程序正常关闭,缓冲区的内容也会写入文件

	while(1)
	{
		//fputs("i am so happy!!!\n", fp); //瞬间就几十M了
		NULL; //目的不让程序结束
	}

	return 0;
}
