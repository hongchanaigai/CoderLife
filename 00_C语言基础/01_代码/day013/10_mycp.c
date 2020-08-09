/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-09 00:55
 * Last modified  : 2020-08-09 00:55
 * Filename       : 10_mycp.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("error: ./a.out src dst\n");
		return 0;
	}

	//1. 打开源文件 argv[1] r
	FILE *r_fp = fopen(argv[1], "r");

	//2. 打开目的文件 argv[2] w
	FILE *w_fp = fopen(argv[2], "w");
	
	//循环操作
	//从源文件读取内容,再把内容写入到目的文件,读多少写多少
	char buf[4*1024];
	int len;
	while(1)
	{
		len = fread(buf, 1, sizeof(buf), r_fp);
		printf("len = %d\n", len);
		if(0 == len)
		{
			break;
		}
		fwrite(buf, 1, len, w_fp);
	}
	
	//3. 关闭文件
	fclose(r_fp);
	fclose(w_fp);

	return 0;
}
