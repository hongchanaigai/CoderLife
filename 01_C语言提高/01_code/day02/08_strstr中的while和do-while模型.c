#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>	//strstr(),strlen()

int main00(void)
{
	char* p = "12abcd130abcd74abcd243abcd239asvcah";
	int n = 0;

	do
	{
		p = strstr(p, "abcd");
		if (p != NULL)
		{
			n++;	//�ҵ�ƥ���ַ���,�ۼӸ���
			//�������ò������
			p += strlen("abcd");

		}
		else
		{	//���û��ƥ���ַ���,����ѭ��
			break;
		}
	} while (*p != '\0');	//���û�е��ַ�����β

	printf("n = %d\n", n);

	printf("\n");
	system("pause");
	return 0;
}

int main01(void)
{
	char* p = "12abcd130abcd74abcd243abcd239asvcah";
	int n = 0;

	while ( p = strstr(p, "abcd") )
	{//�ܽ����϶���ƥ����ַ���
		n++;	//û��������,�ۼӸ���
		p += strlen("abcd");	//�������ò������
		if (*p == '\0')
		{//��������,�˳�ѭ��
			break;
		}
	}

	printf("n = %d\n", n);

	printf("\n");
	system("pause");
	return 0;
}

int my_strstr(char* p, int* n)
{
	//��������
	char* tmp_p = p;
	int tmp_n = 0;

	while ( tmp_p = strstr(tmp_p, "abcd") )
	{//�ܽ����϶���ƥ����ַ���
		tmp_n++;	//û��������,�ۼӸ���
		tmp_p += strlen("abcd");	//�������ò������
		if (*tmp_p == '\0')
		{//��������,�˳�ѭ��
			break;
		}
	}

	//��Ӹ�ֵ
	*n = tmp_n;

	return 0;
}

int main(void)
{
	char* p = "12abcd130abcd74abcd243abcd239asvcah";
	int n = 0;
	int ret = 0;
	ret = my_strstr(p, &n);
	if (ret != 0)
	{
		printf("my_strstr error: %d\n", ret);
		return ret;
	}

	printf("n = %d\n", n);

	printf("\n");
	system("pause");
	return 0;
}