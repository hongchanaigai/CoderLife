/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-08 23:52
 * Last modified  : 2020-08-09 00:26
 * Filename       : 08_fread使用.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

typedef struct Student
{
	int age;
	char name[50];
}Student;

int main()
{
	FILE *fp = fopen("7.txt", "r"); //打开文件

	Student s[10];

	//1. 如果文件内容大小 > 用户指定的读取大小,返回值为用户指定的块数目
	//int ret = fread(&s[0], sizeof(Student), 2, fp);
	//2. 如果文件内容大小 < 用户指定的读取大小,返回值为实际读取的块数目
	//   实际读取的块数目 < 用户指定的读取大小,也有可能为0
	//int ret = fread(&s[0], sizeof(Student), 10, fp);
	//   由于用户指定要10*sizeof(s)的大小,文件只有0.4个大小,返回值为0
	//int ret = fread(&s[0], sizeof(s), 10, fp);
	
	//返回值不可能出现0
	//如果把块大小指定为1,返回值就是读取文件的总大小
	int ret = fread(&s[0], 1, sizeof(s)*10, fp);
	printf("ret = %d\n", ret);

	int i;
	for(i = 0; i < 4; ++i)
	{
		printf("%d %s\n", s[i].age, s[i].name);
	}

	fclose(fp);

	return 0;
}

int main01()
{
	FILE *fp = fopen("7.txt", "w"); //打开文件

	Student s1 = {18, "haung"};
	//&s1,需要往文件写内容的变量首地址
	//sizeof(Student),往文件写入内容的块大小
	//1,往文件写入内容的块数目,写入文件的大小 = 块大小 * 块数目
	//fp,操作的文件
	//返回值:成功返回写入文件的块数目
	//int ret = fwrite(&s1, sizeof(Student), 1, fp);
	int ret = fwrite(&s1, 1, sizeof(Student),fp);
	printf("ret = %d\n", ret);
	printf("sizeof(Student) = %ld\n", sizeof(Student));

	fclose(fp); //关闭文件

	return 0;
}
