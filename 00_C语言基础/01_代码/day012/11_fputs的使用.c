/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 20:35
 * Last modified  : 2020-08-07 20:35
 * Filename       : 11_fputs的使用.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main()
{
	//打开文件
	FILE *fp = fopen("a.txt", "w");

	//写文件
	char *p1 = "hello\n";
	fputs(p1, fp);

	char *p2 = "abc\n";
	fputs(p2, fp);

	char *p3 = "huang\n";
	fputs(p3, fp);

	//指针数组,它是数组,每个元素都是指针
	char *p[] = {"hello\n", "abc\n", "huang\n"};
	int i;
	int n = sizeof(p) / sizeof(p[0]);
	for(i = 0; i < n; ++i)
	{
		fputs(p[i], fp);
	}

	//关闭文件
	fclose(fp);

	return 0;
}

int main01()
{
	char buf[] = "hello\n";
	//把buf的内容写到stdout所代表的文件
	fputs(buf, stdout);

	char *p = "huang";
	fputs(p, stdout);

	return 0;
}
