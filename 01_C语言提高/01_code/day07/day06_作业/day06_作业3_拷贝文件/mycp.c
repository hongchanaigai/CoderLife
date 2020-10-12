/*
3. �ļ������������Ӳο���03_�����ļ���
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),scanf(),perror(),exit(),fopen(),fclose(),fread(),fwrite()
#include <stdlib.h>	//system()
#include <string.h>	//strcmp()

#define SIZE 1024*2	//ÿ��д��2k������

/// <summary>
/// ����˵�
/// </summary>
void menu()
{
	printf("\n*********************************");
	printf("\n\t1. copy a file");
	printf("\n\t2. clear the screen");
	printf("\n\t3. exit");
	printf("\n*********************************");
}

/// <summary>
/// ����һ���ļ�
/// </summary>
void myCopy()
{
	char src_path[256] = { 0 };	//Դ�ļ��ļ�·��
	char dst_path[256] = { 0 };	//Ŀ���ļ��ļ�·��
	int ret = 0;	//��������ֵ,��麯�������Ƿ����

	FILE* src_fp = NULL;	//Դ�ļ��ļ�ָ��
	FILE* dst_fp = NULL;	//Ŀ���ļ��ļ�ָ��
	char buf[SIZE] = { 0 };	//�����ļ�ʱ����ʱ�ڴ�
	int n = 0;

	/*��ʾ�����ļ�*/

	//��ʾ����Դ�ļ�
	printf("\nplease input the source file: ");
	ret = scanf("%s", src_path);
	if (ret == -1)
	{
		perror("myCopy: scanf error(src_path)");
		return;
	}

	//��ʾ����Ŀ���ļ�
	printf("\nplease input the destination file: ");
	ret = scanf("%s", dst_path);
	if (ret == -1)
	{
		perror("myCopy: scanf error(dst_path)");
		return;
	}

	//��ʾԴ�ļ���Ŀ���ļ�������ͬ
	ret = strcmp(src_path, dst_path);
	if (0 == ret)
	{
		printf("\nthe source and destination files can not be the same");
		return;
	}

	/*���ļ�*/

	//��ֻ���ķ�ʽ��Դ�ļ�(2����)
	src_fp = fopen(src_path, "rb");
	if (src_fp == NULL)
	{
		perror("myCopy: fopen error(scr_fp)");
		return;
	}

	//��ֻд�ķ�ʽ��Ŀ���ļ�(2����)
	dst_fp = fopen(dst_path, "wb");
	if (dst_fp == NULL)
	{
		perror("myCopy: fopen error(dst_fp)");
		//��ʱԴ�ļ��Ѿ���,��Ҫ�ر�
		goto CloseSrcFile;
		return;
	}

	/*��д�ļ�*/

	//��ʼ�����ļ�,������д����
	do
	{
		n = 0;	//ÿ��ѭ����Ҫ��0
		//������д����
		n = fread(buf, sizeof(char), SIZE, src_fp);
		printf("\ncopy: %d", n);

		ret = fwrite(buf, sizeof(char), n, dst_fp);
		if (ret != n)
		{
			perror("myCopy: fwrite error");
			//��ʱԴ�ļ�,Ŀ���ļ�N�Ѿ���,��Ҫ�ر�
			goto CloseSrcFile;
			goto CloseDstFile;
			return;
		}

	} while (n > 0);

	printf("\nthe file copy is complete");

	/*�ر��ļ�*/

	//�ر�Դ�ļ�
CloseSrcFile:
	if (src_fp != NULL)
	{
		fclose(src_fp);
		src_fp == NULL;
	}

	//�ر�Ŀ���ļ�
CloseDstFile:
	if (dst_fp != NULL)
	{
		fclose(dst_fp);
		dst_fp == NULL;
	}
}

int main(void)
{
	int cmd = 0;	//�û����������
	int ret = 0;	//��������ֵ,���麯�������Ƿ����
	
	while (1)
	{
		menu();	//����˵�

		printf("\nplease input a command: ");
		ret = scanf("%d", &cmd);
		if (ret == -1)
		{//scanf()�������ó���
			perror("main: scanf error");
			return -1;
		}

		switch (cmd)
		{
		case 1:
			//�����ļ�
			myCopy();
			break;
		case 2:
			//����
			system("cls");
			break;
		default:
			//�˳�����
			exit(0);
		}
	}

	printf("\n");
	system("pause");
	return 0;
}