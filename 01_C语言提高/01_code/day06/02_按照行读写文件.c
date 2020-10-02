#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),fopen(),perror(),fclose(),fputs(),fgets(),feof()
#include <stdlib.h>	//system()
#include <string.h>

void my_fputs(char* path)
{
	FILE* fp = NULL;

	/*���ļ�*/
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fputs: fopen");
		return;
	}

	/*д�ļ�*/
	char* buf[] = { "aaaaa\n", "bbbbbb\n", "ccccccc\n" };
	int n = 3;

	for (int i = 0; i < n; ++i)
	{
		//fputs��������ֵ: �ɹ�����0,ʧ�ܷ��ط�0
		int re_fputs = fputs(buf[i], fp);
		printf("re_fputs = %d\n", re_fputs);
	}

	/*�ر��ļ�*/
	fclose(fp);
	fp = NULL;
}

void my_fgets(char* path)
{
	FILE* fp = NULL;

	/*���ļ�*/
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fgets: fopen");
		return;
	}

	/*���ļ�*/
	int buf[50] = { 0 };

	while (!feof(fp))	//�ļ�û�н���
	{
		//fgets��������ֵ: �ɹ����ض�ȡ���ַ���,ʧ�ܷ���NULL
		//��"\n"���ȡ,��"\n"��Ϊ���еı�ʶ
		//fgets()��ȡ��Ϻ�,�Զ����ַ���������0
		//sizeof(buf)�����ܴ�ŵ��ַ��������ֵ,�Ų���ֻ�ܷ�sizeof(buf),��������ʵ�ʴ�С���
		char* re_fgets = fgets(buf, sizeof(buf), fp);
		if (re_fgets != NULL)
		{
			printf("re_fgets = %s\n", re_fgets);
		}
	}

	/*�ر��ļ�*/
	fclose(fp);
	fp = NULL;
}

int main(void)
{
	my_fputs("../02.txt");	//д�ļ�
	my_fgets("../02.txt");	//���ļ�

	printf("\n");
	system("pause");
	return 0;
}