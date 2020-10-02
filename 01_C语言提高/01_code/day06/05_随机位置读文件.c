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

	/*���ļ�*/
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fwrite: fopen");
		return;
	}

	/*д�ļ�*/
	Student s[3];
	memset(s, 0, 3 * sizeof(Student));

	for (int i = 0; i < 3; ++i)
	{
		char buf[20] = { 0 };
		sprintf(buf, "student%d%d%d", i, i, i);
		strcpy(s[i].name, buf);

		s[i].id = 10 + i;
	}

	//���鷽ʽд�ļ�
	//1. s:					��Ҫд�뵽�ļ������ݵ��׵�ַ
	//2. sizeof(Student):	�����ݵĴ�С
	//3. 3:					��Ҫд������ݿ�Ŀ���
	//4. fp:				�ļ�ָ��
	//д���ļ������ݵĴ�С: sizeof(Student) * 3
	//����ֵ: �ɹ�(д���ļ��Ŀ���Ŀ),ʧ��()
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

	/*�ر��ļ�*/
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fread(char* path)
{
	FILE* fp = NULL;

	/*���ļ�*/
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fread: fopen");
		return;
	}

	/*Student s[3];
	memset(s, 0, 3 * sizeof(Student));*/

	Student tmp;	//����3���ṹ��

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
	/*���ļ�*/
		//���鷽ʽ���ļ�
	//1. s:					���ļ��ж�ȡ�������ݵ��ڴ����׵�ַ
	//2. sizeof(Student):	�����ݵĴ�С
	//3. 3:					��Ҫ��ȡ�����ݿ�Ŀ���
	//4. fp:				�ļ�ָ��
	//��ȡ�ļ����ݵ����ݵĴ�С: sizeof(Student) * 3
	//����ֵ: �ɹ�(��ȡ�ļ����ݵĿ���Ŀ),ʧ��()
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

	/*�ر��ļ�*/
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main(void)
{
	my_fwrite("../05.txt");	//����д�ļ�
	my_fread("../05.txt");	//������ļ�

	printf("\n");
	system("pause");
	return 0;
}