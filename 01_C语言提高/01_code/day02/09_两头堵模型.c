#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>	//strlen(),strncpy()
#include <ctype.h>	//isspace()

int main00(void)
{
	char* p = "          123456789         ";
	int begin = 0;
	int end = strlen(p) - 1;

	//����߿�ʼ
	//�����ǰ�ַ�Ϊ��,��û�е�������
	while (isspace(p[begin]) && p[begin] != '\0')
	{
		begin++;	//λ�������ƶ�һλ
	}
	
	//���ұ߿�ʼ
	//�����ǰ�ַ�Ϊ��,��û�е�������
	while (isspace(p[end]) && p[end] != '\0')
	{
		end--;	//λ�������ƶ�һλ
	}

	int n = 0;
	n = end - begin + 1;
	printf("n = %d\n", n);

	printf("\n");
	system("pause");
	return 0;
}

int fun(char* p, int* n)
{
	if (p == NULL || n == NULL)
	{
		return -1;
	}

	char* tmp_p = p;
	int begin = 0;
	int end = strlen(tmp_p) - 1;

	//����߿�ʼ
	//�����ǰ�ַ�Ϊ��,��û�е�������
	while (isspace(tmp_p[begin]) && tmp_p[begin] != '\0')
	{
		begin++;	//λ�������ƶ�һλ
	}
	
	//���ұ߿�ʼ
	//�����ǰ�ַ�Ϊ��,��û�е�������
	while (isspace(tmp_p[end]) && tmp_p[end] != '\0')
	{
		end--;	//λ�������ƶ�һλ
	}

	int tmp_n = 0;
	tmp_n = end - begin + 1;

	*n = tmp_n;

	return 0;
}

int fun2(char* p, char* buf)
{
	if (p == NULL || buf == NULL)
	{
		return -1;
	}

	char* tmp_p = p;
	int begin = 0;
	int end = strlen(tmp_p) - 1;

	//����߿�ʼ
	//�����ǰ�ַ�Ϊ��,��û�е�������
	while (isspace(tmp_p[begin]) && tmp_p[begin] != '\0')
	{
		begin++;	//λ�������ƶ�һλ
	}
	
	//���ұ߿�ʼ
	//�����ǰ�ַ�Ϊ��,��û�е�������
	while (isspace(tmp_p[end]) && tmp_p[end] != '\0')
	{
		end--;	//λ�������ƶ�һλ
	}

	int n = 0;
	n = end - begin + 1;	//�ǿյ�Ԫ�ظ���

	strncpy(buf, tmp_p + begin, n);
	buf[n] = '\0';

	return 0;
}

int main(void)
{
	char* p = "          123456789         ";
	int n = 0;
	int ret = 0;

	ret = fun(p, &n);
	if (ret != 0)
	{
		printf("fun error!!!\n");
		return ret;
	}

	printf("n = %d\n", n);


	int ret2 = 0;
	char buf[100] = { 0 };

	ret2 = fun2(p, buf);
	if (ret2 != 0)
	{
		printf("fun2 error!!!\n");
		return ret2;
	}

	printf("buf = %s\n", buf);

	printf("\n");
	system("pause");
	return 0;
}