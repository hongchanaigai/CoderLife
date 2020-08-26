#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>	//strcmp(),strcpy()

void print_array(char a[][10], int na)
{
	for (int i = 0; i < na; ++i)
	{
		printf("a[%d] = [%s]\n", i, a[i]);
	}
}

void sort_array(char a[][10], int na)
{
	char tmp[10] = { 0 };
	for (int i = 0; i < na - 1; ++i)
	{
		if (strcmp(a[i], a[i + 1]) > 0)
		{
			strcpy(tmp, a[i]);
			strcpy(a[i], a[i + 1]);
			strcpy(a[i + 1], tmp);
		}
	}
}

int main(void)
{
	char a0[10] = "22222222";
	char a1[10] = "11111111";
	char a2[10] = "bbbbbbbb";
	char a3[10] = "aaaaaaaa";

	//4��a[10]��һά����,��ά����
	//�����ά����,��д��һ��[]������,�����ʼ��
	//a�������е�ַ,���е�ַ��������Ԫ�ص�ַ������,�������ǵ�ֵ���
	//����: ������һ��
	char a[][10] = { "22222222", "11111111", "bbbbbbbb", "aaaaaaaa" };
	int na = sizeof(a) / sizeof(a[0]);

	printf("before sorting: \n");
	print_array(a, na);

	sort_array(a, na);

	printf("\nafter sorting: \n");
	print_array(a, na);

	printf("\n");
	system("pause");
	return 0;
}