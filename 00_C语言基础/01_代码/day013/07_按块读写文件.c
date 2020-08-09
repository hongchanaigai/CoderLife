/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-08 23:52
 * Last modified  : 2020-08-08 23:52
 * Filename       : 07_按块读写文件.c
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
	FILE *fp = fopen("7.txt", "w"); //打开文件

	Student s[4] = 
	{
		{18, "huang"},
		{19, "huang1"},
		{20, "huang2"},
		{21, "huang3"}
	};
	//s,需要往文件写内容的变量首地址
	//sizeof(s),往文件写入内容的块大小
	//1,往文件写入内容的块数目,写入文件的大小 = 块大小 * 块数目
	//fp,操作的文件
	//返回值:成功返回写入文件的块数目
	int ret = fwrite(&s, sizeof(s), 1, fp);

	fclose(fp); //关闭文件

	fp = fopen("7.txt", "r");
	Student s1[10];
	int ret1 = fread(&s1[0], sizeof(Student), 4, fp); //失败返回值为0
	printf("ret1 = %d\n", ret1);

	int i;
	for(i = 0; i < 4; ++i)
	{
		printf("%d %s\n", s1[i].age, s1[i].name);
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
