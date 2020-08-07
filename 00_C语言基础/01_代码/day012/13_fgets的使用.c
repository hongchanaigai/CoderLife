/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 20:43
 * Last modified  : 2020-08-07 20:53
 * Filename       : 13_fgets的使用.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //memset()

int main()
{
	//打开文件
	FILE *fp = fopen("a.txt", "r");

	//读文件
	char buf[100];
	//从fp所关联的文件读取内容,放到buf,一次最大读取为sizeof(buf)-1
	//遇到换行符,文件结尾,出错,结束本次读取
	while(1)
	{
		fgets(buf, sizeof(buf), fp);
		printf("buf = %s", buf);
		if(feof(fp)) //到文件结尾,退出循环
		{
			break;
		}
	}

	//关闭文件
	fclose(fp);

	return 0;
}
