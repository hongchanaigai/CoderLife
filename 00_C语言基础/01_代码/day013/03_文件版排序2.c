/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-08 18:13
 * Last modified  : 2020-08-08 22:31
 * Filename       : 03_文件版排序2.c
 * Description    : 产生500个100以内的随机数,每写一个数字后换行,读取文件,并在屏幕显示
 * *******************************************************/
#include <stdio.h>
#include <time.h> //time()
#include <stdlib.h> //srand(),rand()
#include <string.h> //strcat()

#define MAX 500

void write_file()
{
	FILE *fp = NULL;
	fp = fopen("3.txt", "w"); //写方式打开文件
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
	fp = fopen("3.txt", "r"); //读方式打开
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

	//数组排序,冒泡排序
	int tmp, j;
	for(i = 0; i < n-1; ++i)
	{
		for(j = 0; j < n-1-i; ++j)
		{
			if(a[j] > a[j+1]) //升序
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}

	fclose(fp); //关闭文件
	fp = NULL;

	//关闭后重新写入文件
	fp = fopen("3.txt", "w"); //清空
	fclose(fp);

	fp = fopen("3.txt", "a"); //追加

	char dst[1024 * 4] = {0};
	char src[512];
	for(i = 0; i < n; ++i)
	{
		//printf("%3d ", a[i]);
		sprintf(src, "%d\n", a[i]);
		fputs(src, fp);
	}

	fclose(fp);
}

int main()
{
	write_file();
	read_file();

	return 0;
}
