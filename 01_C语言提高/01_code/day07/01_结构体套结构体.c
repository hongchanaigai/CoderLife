#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

typedef struct A
{
	int a;
	int b;
	char* p;
}A;

/*
1. �ṹ�����Ƕ������һ���ṹ����κ����ͱ���
2. �ṹ��Ƕ�ױ��ṹ����ͨ����(������,���ṹ������ʹ�С�޷�ȷ��)
	���ͱ���: �̶���С�ڴ�����
3. �ṹ��Ƕ�ױ��ṹ��ָ�����(����,���ṹ������ʹ�С����ȷ��)
	ָ������Ŀռ����ȷ��
	ָ�����: 32λ,4�ֽ�	64λ,8�ֽ�
*/
typedef struct B
{
	int a;
	A tmp1;	//ok
	A* p1;	//ok

	//struct B tmp2;	//error
	struct B* p2;	//ok
}B;

int main(void)
{
	printf("\n");
	system("pause");
	return 0;
}