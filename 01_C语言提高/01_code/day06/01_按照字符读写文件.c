#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),fputc(),fgets(),fprintf(),fopen(),perror(),fclose(),feof()
#include <stdlib.h>	//system()
#include <string.h>	//strlen()

int main00(void)
{
	fputc('a', stdout);	//stdout -> 屏幕,打印普通信息

	char ch;
	ch = fgetc(stdin);	//stdin -> 键盘
	printf("ch = %c\n", ch);

	fprintf(stderr, "%c", ch);	//stderr -> 屏幕,打印错误信息
	fputc(ch, stderr);

	printf("\n");
	system("pause");
	return 0;
}


int main01(int argc, char* argv[])
{
	FILE* fp = NULL;

	//打开文件

	//下面两个等级
	//D:\\CoderLife\\Project1\\Project1\\01.txt		windows的写法
	//D:/CoderLife/Project1/Project1/01.txt			windows,linux都支持,建议写"/"

	//绝对路径,D:\\CoderLife\\Project1\\Project1\\01.txt
	//相对路径,/,45度,./,../(建议),linux,windows

	//vs:编译代码时,相对于项目工程
	//直接运行可执行程序,相对于程序

	//长字符串换行写,没写完使用"\"换行,"1234567890"\
		"hfqieugherghoqehgio"
	char* p = "2164964103572035720"\
		"cbisvbeorgheogjpwkdcpwe";
	printf("p = %s\n", p);

	fp = fopen("./01.txt", "w+");
	//fp = fopen("./01.txt", "r+");
	if (fp == NULL)
	{
		perror("main: fopen");
		system("pause");
		return -1;
	}

	//关闭文件
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	printf("\n");
	system("pause");
	return 0;
}


void my_fputc(char* path)
{
	FILE* fp = NULL;

	/*打开文件*/
	//"w+": 写读方式打开,文件不存在,则创建;文件存在,清空内容重写
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		//perror函数参数: 字符串
		perror("my_fputc: fopen");
		return;
	}

	/*写文件*/
	char* buf = "this is a test for fputc";
	int n = strlen(buf);

	for (int i = 0; i < n; ++i)
	{
		//返回值: 成功返回写入的字符,失败返回EOF
		int re_fputc = fputc(buf[i], fp);
		printf("re_fputc = %c\n", re_fputc);
	}

	/*关闭文件*/
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fgetc(char* path)
{
	FILE* fp = NULL;

	/*打开文件*/
	//"r+": 读写方式打开,文件不存在,打开失败
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_getc: fopen");
		return;
	}

	/*读文件*/
	char ch = 0;

#if 0
	while ((ch = fgetc(fp)) != EOF)
	{
		printf("%c", ch);
	}
	printf("\n");
#endif // 0

	while (!feof(fp))	//文件没有结束
	{
		ch = fgetc(fp);
		printf("%c", ch);
	}
	printf("\n");

	/*关闭文件*/
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main(int argc, char* argv[])
{
	my_fputc("../01.txt");	//写文件
	my_fgetc("../01.txt");	//读文件

	printf("\n");
	system("pause");
	return 0;
}