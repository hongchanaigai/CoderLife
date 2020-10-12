#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>	//printf,fopen,perror,feof,fgets,fclose,fseek,ftell,sprintf,fprintf
#include <stdlib.h>
#include <string.h>	//strlen,strncpy,memset,strstr,strchr,strcat
#include <ctype.h>	//isspace

//�ļ�����С
#define MAXSIZE 8 * 1024 //8K

/*
���ܣ�ȥ���ַ������˵Ŀ��ַ�,��ȡ�ǿ��ַ���
������
	inbuf�� ԭʼ�ַ���buf�׵�ַ
	outbuf���ǿ��ַ���buf�׵�ַ
����ֵ��
	�ɹ���0
	ʧ�ܣ���0
*/
int trimSpace(char* inbuf, char* outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		printf("trimSpace: input error: inbuf == NULL || outbuf == NULL\n");
		return -1;
	}

	char* tmp_inbuf = inbuf;	//	��ʱ����,���޸�ԭʼ�ַ���
	int begin = 0;	//�ַ�����ʼλ��
	int end = strlen(tmp_inbuf) - 1;	//�ַ�����βλ��
	int n = 0;	//�洢�ǿ�Ԫ�ظ���

	if (end < 0) 
	{
		printf("trimSpace error: end < 0\n");
		return -2;
	}

	//���������ƶ��������ǰ�ַ�Ϊ�գ�����û�н���
	while (isspace(tmp_inbuf[begin]) && tmp_inbuf[begin] != '\0')
	{
		begin++; //λ�������ƶ�һλ
	}

	//���������ƶ��������ǰ�ַ�Ϊ��
	while (isspace(tmp_inbuf[end]) && end > 0)
	{
		end--; //λ�������ƶ�һλ
	}

	if (end == 0)
	{
		printf("trimSpace error: end == 0\n");
		return -2;
	}

	n = end - begin + 1; //�ǿ�Ԫ�ظ���

	strncpy(outbuf, tmp_inbuf + begin, n);
	//��ӽ�����
	outbuf[n] = '\0';

	return 0;
}

//�������ļ�
int readCfgFile(char* fileName, char* pKey, char* pValue, int* pLen)
{

	if (fileName == NULL || pKey == NULL || pValue == NULL || pLen == NULL)
	{
		printf("readCfgFile error: fileName == NULL || pKey == NULL || pValue == NULL || pLen == NULL\n");
		return -1;
	}

	FILE* fp = NULL;
	char buf[1024] = { 0 };
	char* tmp_buf = NULL;
	int flag = 0; //���û��key����Ӧ��value��flag��Ϊ0

	//��(������)��ʽ���ļ�
	fp = fopen(fileName, "rb");
	if (fp == NULL)
	{
		perror("readCfgFile: fopen error");
		return -2;
	}

	//����ļ�û�н���
	while (!feof(fp))
	{
		memset(buf, 0, sizeof(buf));
		tmp_buf = fgets(buf, sizeof(buf), fp);
		if (tmp_buf == NULL)
		{
			break;
		}

		//�ж�ÿ�����Ƿ����key
		tmp_buf = strstr(buf, pKey);
		if (NULL == tmp_buf)//���û�а���key
		{
			continue; //��������ѭ��
		}

		//�������������ַ�����λ�ã�����key��
		// "k1 = 1111" -> " = 1111"
		tmp_buf = tmp_buf + strlen(pKey);

		//�ж��Ƿ����=
		tmp_buf = strchr(tmp_buf, '=');
		if (NULL == tmp_buf)
		{
			continue; //��������ѭ��
		}
		//�������������ַ�����λ��(����=)
		//"= 1111" -> "   1111  "
		tmp_buf = tmp_buf + 1;

		//��ȡ�ǿ��ַ�����ͷ��ģ��
		if (0 == trimSpace(tmp_buf, pValue))
		{
			//���⣬�Ѿ��ҵ�����Ҫ���value
			*pLen = strlen(pValue);
			flag = 1;
		}

		break; //����Ҫ
	}

	if (0 == flag)
	{
		printf("no find a key = %s\n", pKey);
		return -6;
	}

	//�ر��ļ�
	if (fp != NULL)
	{
		fclose(fp);
	}

	return 0;
}

//д���޸������ļ�
//ʵ������
//ѭ����ÿһ��
//���а���key�����key��value�޸�
//��������ж�������key�������ļ���β׷�ӣ� "key = value"
//�ѵ㣺����޸�
int writeCfgFile(char* fileName, char* pKey, char* pValue, int len)
{
	if (fileName == NULL || pKey == NULL || pValue == NULL)
	{
		printf("writeCfgFile error: fileName == NULL || pKey == NULL || pValue == NULL\n");
		return -1;
	}

	FILE* fp = NULL;
	char tmp_buf[MAXSIZE] = { 0 };
	char line_buf[1024] = { 0 };
	int flag = 0; //0: ������key

	//���ļ�����д��ʽ�򿪣��ļ������ڣ���ʧ��
	fp = fopen(fileName, "rb+");
	if (fp == NULL) //�ļ�������ʱ���½��ļ�
	{
		//д����ʽ���ļ����ļ��������򴴽�
		fp = fopen(fileName, "wb+");
		if (fp == NULL)
		{
			perror("writeCfgFile: fopen error");
			return -2;
		}
	}

	//�����ļ�����
	//��ȡ�ļ����ݴ�С�����Ƿ񳬳���Χ

	//���ļ�����ƶ�����β��
	fseek(fp, 0, SEEK_END);

	//��ȡ�ļ����ݴ�С
	long size = ftell(fp);

	//����ļ���С����8k���жϳ���
	if (size >= MAXSIZE)
	{
		printf("writeCfgFile: the size > 8k, error\n");
		fclose(fp);
		return -3;
	}

	//���ļ�����ƶ����ʼλ��
	fseek(fp, 0, SEEK_SET);

	//ѭ����ÿһ��
	//���а���key�����key��value�޸�
	//��������ж�������key�������ļ���β׷�ӣ� "key = value"
	while (!feof(fp))
	{
		if (NULL == fgets(line_buf, sizeof(line_buf), fp))
		{
			break;
		}

		//�����Ƿ����key
		if (strstr(line_buf, pKey) != NULL) //����
		{
			//��д��line_buf��ʽ��
			sprintf(line_buf, "%s = %s\n", pKey, pValue);
			strcat(tmp_buf, line_buf);
			flag = 1;
		}
		else
		{
			strcat(tmp_buf, line_buf);
		}
	}


	if (0 == flag) //�ļ���û��keyֵ
	{//��������ж�������key�������ļ���β׷�ӣ� "key = value"

		//����һ�����ļ�����Ѿ��ƶ�����β��
		//�����ʱ���ļ���д���ݣ��϶���׷�ӵ���β��
		//��ʽ����ʽд�ļ�
		fprintf(fp, "%s = %s\n", pKey, pValue);
	}
	else
	{	//�ر��ļ�
		//��д��д��ʽ���ļ�����д���ļ�д����
		if (fp != NULL)
		{
			fclose(fp);
			fp = NULL;
		}

		//д����ʽ���ļ����ļ��������򴴽�
		fp = fopen(fileName, "wb+");
		if (fp == NULL)
		{
			perror("writeCfgFile: fopen error");
			return -4;
		}

		//���ļ�д����
		fputs(tmp_buf, fp);
	}


	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return  0;
}