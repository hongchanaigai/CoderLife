#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),sprintf(),fopen(),perror(),fclose(),fwrite(),fread(),fseek()
#include <stdlib.h>	//system()
#include <string.h>	//memset(),strcpy()

typedef struct Student
{
	char name[20];
	int id;
}Student;

void my_fwrite(char* path)
{
	FILE* fp = NULL;

	/*打开文件*/
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fwrite: fopen");
		return;
	}

	/*写文件*/
	Student s[3];
	memset(s, 0, 3 * sizeof(Student));

	for (int i = 0; i < 3; ++i)
	{
		char buf[20] = { 0 };
		sprintf(buf, "student%d%d%d", i, i, i);
		strcpy(s[i].name, buf);

		s[i].id = 10 + i;
	}

	//按块方式写文件
	//1. s:					需要写入到文件的内容的首地址
	//2. sizeof(Student):	块数据的大小
	//3. 3:					需要写入的数据块的块数
	//4. fp:				文件指针
	//写入文件的数据的大小: sizeof(Student) * 3
	//返回值: 成功(写入文件的块数目),失败()
	int re_fwrite = fwrite(s, sizeof(Student), 3, fp);
	/*printf("re_fwrite = %d\n", re_fwrite);*/

	if (re_fwrite != 3)
	{
		printf("my_fwrite: fwrite error: re_fwrite == %d\n", re_fwrite);
		return;
	}

	/*for (int i = 0; i < 3; ++i)
	{
		printf("%s, %d\n", s[i].name, s[i].id);
	}*/

	/*关闭文件*/
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fread(char* path)
{
	FILE* fp = NULL;

	/*打开文件*/
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fread: fopen");
		return;
	}

	/*Student s[3];
	memset(s, 0, 3 * sizeof(Student));*/

	Student tmp;	//读第3个结构体

	fseek(fp, 2 * sizeof(Student) + 1, SEEK_SET);

	int re_fread = fread(&tmp, sizeof(Student), 1, fp);
	/*printf("re_fread = %d\n", re_fread);*/

	if (re_fread != 1)
	{
		printf("my_fread: fread error: re_fread == %d\n", re_fread);
		return;
	}

	printf("tmp: %s, %d\n", tmp.name, tmp.id);

#if 0
	/*读文件*/
		//按块方式读文件
	//1. s:					放文件中读取到的内容的内存块的首地址
	//2. sizeof(Student):	块数据的大小
	//3. 3:					需要读取的数据块的块数
	//4. fp:				文件指针
	//读取文件内容的数据的大小: sizeof(Student) * 3
	//返回值: 成功(读取文件内容的块数目),失败()
	int re_fread = fread(s, sizeof(Student), 3, fp);
	/*printf("re_fread = %d\n", re_fread);*/

	if (re_fread != 3)
	{
		printf("my_fread: fread error: re_fread == %d\n", re_fread);
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		printf("%s, %d\n", s[i].name, s[i].id);
	}
#endif // 0

	/*关闭文件*/
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main(void)
{
	my_fwrite("../05.txt");	//按块写文件
	my_fread("../05.txt");	//按块读文件

	printf("\n");
	system("pause");
	return 0;
}