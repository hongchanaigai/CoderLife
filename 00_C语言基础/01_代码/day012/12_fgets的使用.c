/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 20:43
 * Last modified  : 2020-08-07 20:43
 * Filename       : 12_fgets的使用.c
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
	fgets(buf, sizeof(buf), fp);
	printf("buf = %s\n", buf);

	fgets(buf, sizeof(buf), fp);
	printf("buf = %s\n", buf);

	fgets(buf, sizeof(buf), fp);
	printf("buf = %s\n", buf);

	//以下的读取,由于到文件结尾,读取失败,导致buf保存上一次读取的内容
	memset(buf, 0, sizeof(buf));
	fgets(buf, sizeof(buf), fp);
	printf("buf = %s\n", buf);
	
	//关闭文件
	fclose(fp);

	return 0;
}
