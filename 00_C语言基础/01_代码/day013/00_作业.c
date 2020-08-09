/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-08 18:13
 * Last modified  : 2020-08-08 18:43
 * Filename       : 00_作业.c
 * Description    : 产生500个100以内的随机数,每写一个数字后换行,读取文件,并在屏幕显示
 * *******************************************************/
#include <stdio.h>
#include <time.h> //time()
#include <stdlib.h> //srand(),rand()

#define MAX 500

void write_file()
{
	FILE *fp = NULL;
	fp = fopen("./test.txt", "w"); //写方式打开文件
	if(fp == NULL) //打开失败
	{
		perror("write_file fopen");
		return; //结束程序
	}

	srand((unsigned int)time(NULL)); //设置随机种子

	int i, num;
	char buf[100];
	for(i = 0; i < MAX; ++i) //生成500个随机数
	{
		num = rand() % 100; //随机数控制在100以内
		sprintf(buf, "%d\n", num); //格式化字符串
		fputs(buf, fp); //往文件写入内容
	}

	fclose(fp); //关闭文件
	fp = NULL;
}

void read_file()
{
	FILE *fp = NULL;
	fp = fopen("./test.txt", "r"); //读方式打开
	if(fp == NULL) //打开失败
	{
		perror("read_file fopen");
		return; //退出程序
	}

	int a[1024], i, num;
	char buf[100];
	while(1)
	{
		fgets(buf, sizeof(buf), fp); //读取一行内容,放在buf中
		if(feof(fp)) //文件结尾
		{
			break; //退出循环
		}

		sscanf(buf, "%d\n", &num); //格式化字符串
		a[i] = num;
		++i;
	}

	int n = i; //数组元素个数
	printf("n = %d\n", n);
	for(i = 0; i < n; ++i)
	{
		printf("%3d ", a[i]);
	}
	printf("\n");

	fclose(fp); //关闭文件
	fp = NULL;
}

int main()
{
	write_file();
	read_file();

	return 0;
}
