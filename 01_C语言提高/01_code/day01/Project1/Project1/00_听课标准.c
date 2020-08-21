#include <stdio.h>
#include <stdlib.h> //system()

int main00(void)
{
	int a[] = { 10, 7, 1, 9, 4, 6, 7, 3, 2, 0 };
	int n = sizeof(a) / sizeof(a[0]); //Ԫ�ظ���
	int i = 0;

	printf("before sort: \n");
	for (i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	//ѡ������
	/*
	10, 7, 1, 9, 4, 6, 7, 3, 2, 0
	7, 10,(10 > 7����)
	1, 10, 7, 9, 4, 6, 7, 3, 2,(7 > 1����)
	0, 10, 7, 9, 4, 6, 7, 3, 2, 1(1 > 0����)
	����С�ķ�����ǰ��
	*/
	int j = 0;
	int tmp = 0;
	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (a[i] > a[j]) //����
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	printf("after sort: \n");
	for (i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	//��ο������㷨�ĳ���
	/*
	1.����
	2.ÿ����书��
	3.����
	4.����
	5.ģ�¸�
	6.��������д
	*/

	printf("\n");
	system("pause");
	return 0;
}


//���������Ϊ��������,�����βλ��˻���ָ��,32λϵͳ4�ֽ�
//void print_array(int a[10], int n) //��ӡ����Ԫ��
//void print_array(int a[], int n) //��ӡ����Ԫ��
void print_array(int* a, int n) //��ӡ����Ԫ��
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void sort_array(int* a, int n) //ѡ������
{
	int i, j, tmp;
	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (a[i] > a[j]) //����
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int main(void)
{
	int a[] = { 10, 7, 1, 9, 4, 6, 7, 3, 2, 0 };
	int n = sizeof(a) / sizeof(a[0]); //Ԫ�ظ���
	printf("n = %d\n", n);

	//����ǰ��ӡ
	printf("before sort: \n");
	print_array(a, n);

	//ѡ������
	sort_array(a, n);

	//������ӡ
	printf("after sort: \n");
	print_array(a, n);

	printf("\n");
	system("pause");
	return 0;
}