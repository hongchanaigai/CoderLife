#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

int main(void)
{
	//int b[];	//error	��ָ��Ԫ�ظ���,�����ʼ��
	int c[100] = { 1, 2, 3, 4 };	//û�и�ֵ�Ķ�Ϊ0

	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };	//8��
	int a[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };	//8��
	//sizeof()�������ռ�Ŀռ�(��������Ӧ���͵Ŀռ�)

	int n = 0;
	//sizeof(a) = 4 * 8 = 32	��������: ��"Ԫ�ظ���"��"Ԫ������"����	int [8]
	//sizeof(a[0]) = 4	��Ԫ�ش�С,ÿ��Ԫ��4�ֽ�
	n = sizeof(a) / sizeof(a[0]);	//n = 8

	for (int i = 0; i < n; ++i)
	{
		//*(a+i): a+i�����i��Ԫ�صĵ�ַ,*(a+i)����ָ��ָ����ڴ�
		//[] * �ȼ�
		//printf("%d ", a[i]);
		printf("%d ", *(a + i));
	}
	printf("\n");

	//��������
	//a : ������Ԫ�ص�ַ
	//&a: ����������׵�ַ,��������Ԫ�ص�ַһ��,����,���߲�����һ��
	printf("a : %p, a+1 : %p\n", a, a + 1);	//+4�ֽ�
	printf("&a: %p, &a+1: %p\n\n", &a, &a + 1);	//+32�ֽ�

	//��������: ��"Ԫ�ظ���"��"Ԫ������"����	int [8]
	//ͨ��typedef����һ����������
	//��typedef������,û��typedef�Ǳ���
	typedef int A[8];	//������������,��������,���Ǳ���
	//typedef int(A)[8];
	A b;	//int b[8];	ȥ��typedef,b�滻��A��λ��

	for (int i = 0; i < 8; ++i)
	{
		b[i] = i;
	}

	for (int i = 0; i < 8; ++i)
	{
		//printf("%d ", b[i]);
		printf("%d ", *(b + i));
	}
	printf("\n");

	printf("b : %p, b+1 : %p\n", b, b + 1);	//+4�ֽ�
	printf("&b: %p, &b+1: %p\n", &b, &b + 1);	//+32�ֽ�

	printf("\n");
	system("pause");
	return 0;
}