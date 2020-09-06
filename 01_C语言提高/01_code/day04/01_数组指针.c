#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

//argc: �������ĸ���(������ִ�г���)
//argv: ָ������,ָ������Ĳ���
int main(int argc, char* argv[])
{
	//ָ������,����ָ��

#if 0
	//1. ָ������,��������,ÿ��Ԫ�ض���ָ��
	//		[] �����ȼ��� * ��
	char* a[] = { "aaaaa", "bbbbb", "ccccc" };

	printf("argc = %d\n", argc);

	for (int i = 0; i < argc; ++i)
	{
		printf("argv[%d] = [%s]\n", i, argv[i]);
	}
#endif	//0

#if 0
	//2. ����ָ��,����ָ��,ָ��һ�������ָ��
	//		����ָ��,ָ�����һά�������������,��������Ԫ�صĵ�ַ
	//		��������ָ�����
	//			1) �ȶ�����������,�����������Ͷ���ָ�����
	typedef int(A)[10];	//A��������,[10]������
	A* p = NULL;	//p����ָ�����ͱ���

	int a[10] = { 0 };

	//p = a;	//warning	a������Ԫ�ص�ַ, a �� &a һ��,����Ҳ�ǵ��� &a
	p = &a;	//&a �������������׵�ַ

	printf("p: %p, p+1: %p\n\n", p, p + 1);

	for (int i = 0; i < 10; ++i)
	{
		//a[]
		//p = &a
		//*p = *&a --> a
		(*p)[i] = i;
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", (*p)[i]);
	}
	printf("\n");
#endif	//0

#if 0
	//			2) �ȶ�������ָ������,����ָ�����Ͷ������
	//��ָ������д��������,����()
	//() �� [] ���ȼ�һ��,��������
	//() ��ָ��,����һ��ָ��, [] 
	//ָ�������ָ��,����typedef,��������һ������ָ������
	typedef int(*P)[10];
	P ptr;	//����ָ������

	int a[10] = { 0 };
	ptr = &a;

	for (int i = 0; i < 10; ++i)
	{
		(*ptr)[i] = i + 1;
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", (*ptr)[i]);
	}
	printf("\n");
#endif	//0

	//			3) ֱ�Ӷ�������ָ�����
	//��ָ������д��������,����()
	//() �� [] ���ȼ�һ��,��������
	//() ��ָ��,����һ��ָ��, [] 
	//ָ�������ָ��,��û��typedef,��������һ������ָ�����
	int(*ptr)[10];	//����ָ�����

	int a[10] = { 0 };
	ptr = &a;

	for (int i = 0; i < 10; ++i)
	{
		(*ptr)[i] = i + 2;
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", (*ptr)[i]);
	}
	printf("\n");

	printf("\n");
	system("pause");
	return 0;
}