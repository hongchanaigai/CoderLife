/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-08 23:52
 * Last modified  : 2020-08-09 18:22
 * Filename       : 11_随机位置读写.c
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

	Student s;

	//读取第4个结构体,从开始位置往右偏移3个结构体
	fseek(fp, 3*sizeof(Student), SEEK_SET);
	fread(&s, 1, sizeof(Student), fp);
	printf("%d %s\n", s.age, s.name);

	//回到最开始的位置
	//fseek(fp, 0, SEEK_SET);
	rewind(fp);
	fread(&s, 1, sizeof(Student), fp);
	printf("%d %s\n", s.age, s.name);

	//光标移动到末尾
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	printf("size = %ld\n", size);

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
