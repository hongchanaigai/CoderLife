/*
1. ��һ��δ֪��С���ļ�(��: song.txt )ȫ������(����һ��һ�ж�ȡ)�ڴ棬
	����ʾ����Ļ�ϣ����Ӳο���01_ReadSong��

	�ο���fseek(),  ftell(),  rewind(),  fread(),  malloc()
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),fopen(),perror(),fclose(),fseek(),ftell(),fread()
#include <stdlib.h>	//system()
#include <string.h>	//malloc(),free()

/// <summary>
/// ��һ��δ֪��С���ļ�(��: song.txt )ȫ������(����һ��һ�ж�ȡ)�ڴ棬����ʾ����Ļ��
/// </summary>
/// <param name="path">�ļ�·��</param>
void readSong(char* path)
{
	if (path == NULL)
	{
		printf("readSong error: path == NULL\n");
		return;
	}

	FILE* fp = NULL;	//�ļ�ָ��
	int ret = 0;	//���õĺ�������ֵ,�жϺ��������Ƿ����
	long size = 0;	//�����ļ���С
	char* buf = NULL;	//������̬�����ڴ�
	
	/*�Զ�(������)��ʽ���ļ�*/
	fp = fopen(path, "rb");
	
	//�����ж�,���ļ�ʧ��,��������
	if (fp == NULL)
	{
		perror("readSong: fopen error");
		return;
	}

	/*
	���ļ�
	1. ��ȡ�ļ���С
	2. ������ʵ��ڴ�
	3. ������ļ�
	4. �ͷ��ڴ�
	*/

	/*1. ��ȡ�ļ���С*/

	//����ƶ����ļ���β
	ret = fseek(fp, 0, SEEK_END);
	if (ret != 0)
	{
		perror("readSong: fseek1 error");
		goto CloseFile;	//��ʱ�ļ��Ѿ���,�ȹر��ٽ�������
		return;
	}
	
	//��ȡ�ļ���С
	size = ftell(fp);
	if (size == -1)
	{
		perror("readSong: ftell error");
		goto CloseFile;	//��ʱ�ļ��Ѿ���,�ȹر��ٽ�������
		return;
	}

	//����ƶ����ļ���ͷ
	ret = fseek(fp, 0, SEEK_SET);
	if (ret != 0)
	{
		perror("readSong: fseek2 error");
		goto CloseFile;	//��ʱ�ļ��Ѿ���,�ȹر��ٽ�������
		return;
	}

	/*2. ������ʵ��ڴ�*/
	if (size == 0)
	{//�ļ���СΪ0
		printf("the file size is 0\n");
	}
	else
	{//�ļ���С��Ϊ0,��ʼ������ʴ�С���ڴ�
		buf = (char*)malloc(size * sizeof(char) + 1);
		if (buf == NULL)
		{//�����ڴ�ʧ��,�˳�����
			perror("readSong: malloc error");
			goto CloseFile;	//��ʱ�ļ��Ѿ���,�ȹر��ٽ�������
			return;
		}
	}

	/*3. ������ļ�*/
	ret = fread(buf, size, 1, fp);
	if (ret != 1)
	{//��ȡ�ļ�ʧ��
		perror("readSong: fread error");
		goto FreeBuf;	//��ʱ�ڴ��Ѿ�����,���ͷ��ٽ�������
		goto CloseFile;	//��ʱ�ļ��Ѿ���,�ȹر��ٽ�������
		return;
	}

	//��ȡ�ɹ�,��β����ַ���������
	if (buf != NULL)
	{
		buf[size] = '\0';
	}

	//���
	if (buf != NULL && ret == 1)
	{
		printf("%s\n", buf);
	}

	/*4. �ͷ��ڴ�*/
FreeBuf:
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}

	/*�ر��ļ�*/
CloseFile:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main(void)
{
	readSong("./song.txt");

	printf("\n");
	system("pause");
	return 0;
}