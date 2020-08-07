/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 19:28
 * Last modified  : 2020-08-07 19:28
 * Filename       : 07_feof.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main()
{
	FILE *fp = fopen("7.txt", "r");

	while(1)
	{
		printf("not end!!!\n");
		int ch = fgetc(fp); //读取,为了判断是否结尾
		if(feof(fp)) //文件到结尾,返回真
		{
			break;
		}
	}

	fclose(fp);
	fp = NULL;

	return 0;
}
