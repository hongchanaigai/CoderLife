#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

typedef struct MyStruct
{
	int a;
	int b;
}MyStruct;

void fun1(MyStruct* p)
{
	//ָ���ܱ�
	//p = NULL;	//ok
	//ָ��ָ����ڴ��ܱ�
	p->a = 10;	//ok
}

void fun2(MyStruct const* p)
{
	//ָ���ܱ�
	//p = NULL;	//ok
	//ָ��ָ����ڴ治�ܱ�
	//p->a = 10;	//error
}

void fun3(MyStruct* const p)
{
	//ָ�벻�ܱ�
	//p = NULL;	//error
	//ָ��ָ����ڴ��ܱ�
	p->a = 10;	//ok
}

void fun4(MyStruct const* const p)
{//ֻ��
	//ָ�벻�ܱ�
	//p = NULL;	//error
	//ָ��ָ����ڴ治�ܱ�
	//p->a = 10;	//error
	MyStruct tmp;
	tmp.a = p->a;
}

int main(void)
{
#if 0
	//const����һ������Ϊֻ��
	const int a = 10;
	//a = 100;	//error

	//ָ�����,ָ��ָ����ڴ�,��2����ͬ����
	char buf[] = "afgsihefoqejfrp";

	//�������ҿ�,��������,�������Ǹ��ַ�
	//�����*,˵��ָ��ָ����ڴ治�ܸı�
	//�����ָ�����,˵��ָ���ָ���ܸı�
	const char* p1 = buf;	//�ȼ���char const* p1 = buf;
	//p1[1] = '1';	//error
	p1 = "gsiafhojwceiwejif";	//ok
	
	char* const p2 = buf;
	p2[1] = '1';	//ok
	//p2 = "caifhcoajdekoeqkc";	//error

	const char* const p3 = buf;
	//p3Ϊֻ��,ָ���ܸı�,ָ����ڴ�Ҳ���ܸı�
#endif // 0

	//�����������һ��.c�е�const����,�˽�
	extern const int a;	//ֻ������,�����ٸ�ֵ

	//const���εı���,����ʱ��ʼ��
	const int b = 10;
	//b = 100;	//error
	int* p = &b;
	*p = 100;	//ok,����޸�const����b��ֵ
	printf("*p = %d, b = %d\n", *p, b);

	printf("\n");
	system("pause");
	return 0;
}