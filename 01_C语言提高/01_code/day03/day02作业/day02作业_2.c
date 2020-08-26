/*
2. ��һ���ַ�����ͷ���β����n���ո� ����   abcdefgdddd    ��������ȥ��ǰ��ո񣬷���һ�����ַ�����
	Ҫ��1�����Լ�����һ���ӿڣ�����������ʵ�ֹ��ܣ�
	Ҫ��2����д����������
	int trimSpace(char *inbuf, char *outbuf);
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>	//strlen(),strncpy()
#include <ctype.h>	//isspace()

int trimSpace(char* inbuf, char* outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}

	char* tmp_inbuf = inbuf;	//��������,��ֱ��ʹ���β�
	int begin = 0;	//�ַ�����Ԫ���±�
	int end = strlen(tmp_inbuf) - 1;	//�ַ���βԪ���±�

	//����Ԫ�ؿ�ʼ������
	while (isspace(tmp_inbuf[begin]) && tmp_inbuf[begin] != '\0')
	{
		begin++;
	}

	//��βԪ�ؿ�ʼ������
	while (isspace(tmp_inbuf[end]) && tmp_inbuf[end] != '\0')
	{
		end--;
	}

	int n = end - begin + 1;

	strncpy(outbuf, tmp_inbuf + begin, n);
	outbuf[n] = '\0';	

	return 0;
}

int main(void)
{
	char* inbuf = "   abcdefgdddd    ";
	char outbuf[100] = { 0 };
	int ret = 0;

	ret = trimSpace(inbuf, outbuf);
	if (ret != 0)
	{
		printf("trimSpace error!!!\n");
		return ret;
	}

	printf("inbuf = %s\n", inbuf);
	printf("outbuf = %s\n", outbuf);

	printf("\n");
	system("pause");
	return 0;
}