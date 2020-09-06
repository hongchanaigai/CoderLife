/*
6. ��һ���ַ�������������������abcdef,acccd,eeee,aaaa,e3eeee,ssss,����

	д��������(API)��������½��
	��һ��API(�ڶ����ڴ�ģ�ͣ� ��ά����)
	1)�Զ��ŷָ��ַ������γɶ�ά���飬���ѽ������
	2)�Ѷ�ά��������������Ҳ����
	int spitString(const char *str, char c, char buf[10][30], int* count);

	�ڶ���API(�������ڴ�ģ�ͣ���̬���ɶ�ά�ڴ�)
		1)�Զ��ŷָ��ַ������γ�һ������ָ�롣
		2)��һ����ֶ������ַ�����������
		int spitString2(const char* str, char c, char** myp, int* count);

	Ҫ��
		1, ����ȷ��﹦�ܵ�Ҫ�󣬶�����ӿڡ�
		2, ��ȷʵ�ֽӿں͹���.
		3, ��д��ȷ�Ĳ�������.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system(),malloc(),free()
#include <string.h>	//strchr(),strncpy(),strcpy()

int spitString(const char* str, char c, char buf[10][30], int* count)
{
	if (str == NULL || count == NULL)
	{
		printf("spitString: str/count == NULL\n");
		return -1;
	}
	
	//str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
	const char* start = str;
	char* p = NULL;
	int i = 0;	//buf[i]

	do
	{//�ҵ�
		p = strchr(satrt, c);
		if (p != NULL)
		{
			//str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
			int len = p - satrt;	//len = 6,p = str[6],start = str[0]
			if (len > 0)
			{
				strncpy(buf[i], start, len);	//buf[0] = "abcdef"
				//��ӽ�����
				buf[i][len] = '\0';

				++i;
			}
			//�����������λ��
			//str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
			start = p + 1;	//start = str[7],p = str[6]
		}
		else
		{//û�ҵ�
			strcpy(buf[i], start);	//start = str[30],buf[5] = "ssss"
			++i;	//�ټ�һ��,��֤����count+1,��֤���һ�δ�ӡ����
			break;
		}
	} while (*satrt != 0);
	
	if(i == 0)
	{
		printf("spitString: i == 0\n");
		return -2;
	}

	*count = i; //�ж������ַ���

	return 0;
}

char** getMem(int count)
{
	char** buf = NULL;	//char* buf[count]
	buf = (char**)malloc(count * sizeof(char*)); //char* buf[]
	if (buf == NULL)
	{
		printf("getMem: malloc error, buf == NULL\n");
		return NULL;
	}

	//ÿ��Ԫ�صĿռ�
	for (int i = 0; i < count; ++i)
	{
		buf[i] = (char*)malloc(30 * sizeof(char)); //char buf[]
		if (buf[i] == NULL)
		{
			printf("getMem: malloc error, buf[i] == NULL\n");
			return NULL;
		}
	}

	return buf;
}

void getMemFree(char*** buf, int count)
{
	if (buf == NULL)
	{
		printf("getMemFree: buf == NULL\n");
		return;
	}

	char** tmp = *buf;

	for (int i = 0; i < count; ++i)
	{
		if (tmp[i] != NULL)
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}
	}

	free(tmp);
	*buf = NULL;
}

int spitString2(const char* str, char c, char** buf, int* count)
{
	if (str == NULL || count == NULL)
	{
		return -1;
	}

	char* start = str;
	char* p = NULL;
	int i = 0; //�ڼ���

	do
	{
		//"abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
		p = strchr(start, c);
		if (p != NULL)
		{
			int len = p - start;
			if (len > 0)
			{
				strncpy(buf[i], start, len);
				//��ӽ�����
				buf[i][len] = '\0';

				i++;
			}
			start = p + 1;
		}
		else
		{
			strcpy(buf[i], start);	//start = str[30],buf[5] = "ssss"
			++i;	//�ټ�һ��,��֤����count+1,��֤���һ�δ�ӡ����
			break;
		}
	} while (*start != 0);

	*count = i; //�ж������ַ���

	return 0;
}

int main(void)
{
#if 0
	char* str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	char buf[10][30] = { 0 };
	int count = 0;
	
	int ret = 0;
	ret = spitString(str, ',', buf, &count);
	if (ret != 0)
	{
		printf("main: spitString error: %d\n", ret);
		return ret;
	}
	
	for (int i = 0; i < count; ++i)
	{
		printf("buf[%d] = [%s]\n", i, buf[i]);
	}

#endif	//0

	char* str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	char** buf = NULL;
	
	buf = getMem(6);
	if(buf == NULL)
	{
		printf("main: buf == NULL\n");
		return -1;
	}
	//char** buf = getMem(10); //��̬�����ά����
	
	int count = 0;

	int ret = 0;
	ret = spitString2(str, ',', buf, &count);
	if (ret != 0)
	{
		printf("main: spitString2 error: %d\n", ret);
		return ret;
	}

	for (int i = 0; i < count; ++i)
	{
		printf("buf[%d] = [%s]\n", i, buf[i]);
	}
	
	//�ͷ��ڴ�
	for(int i = 0; i < count; ++i)
	{
		free(buf[i]);
		buf[i] = NULL;
	}
	
	if(buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
	//getMemFree(&buf, count);

	printf("\n");
	system("pause");
	return 0;
}