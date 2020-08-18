/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-09 19:18
 * Last modified  : 2020-08-09 19:18
 * Filename       : 00_作业.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //strlen(),strcpy(),memset()
#include <stdlib.h> //malloc(),free()

typedef struct Student
{
	//如果是指针变量,写文件时,只是把指针的值写入文件
	char *name; //名字
	int id;
	int name_len; //名字长度
}Student;

void write_file()
{
	//打开文件
	FILE *fp = NULL;
	fp = fopen("./0.txt", "wb"); //以二进制方式写入
	if(fp == NULL) //打开失败
	{
		perror("write_file fopen");
		return; //结束程序
	}

	Student s; //定义结构体变量

	//结构体变量赋值
	s.id = 1;
	s.name_len = strlen("huang"); //名字长度
	s.name = (char *)malloc(s.name_len + 1); //指向堆区空间
	strcpy(s.name, "huang");
	
	//写文件
	//1. 先将结构体写入文件
	int ret = fwrite(&s, 1, sizeof(s), fp);
	if(ret < 0) //写入失败
	{
		perror("write_file fwrite1");
		return; //结束程序
	}

	//2. 再将name所关联的字符串写入文件
	ret = fwrite(s.name, 1, s.name_len, fp);
	if(ret < 0) //写入失败
	{
		perror("write_file fwrite2");
		return; //退出程序
	}

	//关闭文件
	fclose(fp);
	fp = NULL;
}

void read_file()
{
	//打开文件
	FILE *fp = NULL;
	fp = fopen("./0.txt", "rb"); //以二进制方式读
	if(fp == NULL) //打开失败
	{
		perror("read_file fopen");
		return; //结束程序
	}

	//读文件
	Student s;
	
	//1. 先将结构体读出来
	int ret = fread(&s, 1, sizeof(s), fp);
	if(ret < 0) //读取失败
	{
		perror("read_file fread1");
		return; //退出程序
	}

	//2. 再读字符串
	s.name = (char *)malloc(s.name_len + 1);
	memset(s.name, 0, s.name_len+1); //清空内存,防止乱码

	ret = fread(s.name, 1, s.name_len, fp);
	if(ret < 0) //读取失败
	{
		perror("read_file fread2");
		return; //退出程序
	}

	//打印读到的内容
	printf("name = %s, id = %d, name_len = %d\n", s.name, s.id, s.name_len);

	//关闭文件
	fclose(fp);
	fp = NULL;
}

int main()
{
	//以二进制方式存放在文件中
	write_file();

	//实现读的接口,并打印读出来的信息
	read_file();

	return 0;
}
