#include <stdio.h>
#include <stdlib.h>	//system()

int get_b1(void)
{
	int b = 10;
	return b;
}

void get_b2(int b)
{
	b = 22;
}

void get_b3(int* b)
{
	*b = 99;	//ͨ��*�����ڴ�
}

void get_a_3(int* a1, int* a2, int* a3)
{
	*a1 = 1;
	*a2 = 2;
	*a3 = 3;
}

int main00(void)
{
	//��Ӹ�ֵ��ָ����ڵ��������

	//��������: һ����ͨ����,һ��ָ�����
	int a = 100;
	int* p = NULL;
	//������ϵ: ָ��ָ��˭,�Ͱ�˭�ĵ�ַ��ֵ��ָ�����
	p = &a;
	//ͨ��*�����ڴ�
	*p = 22;

	/*
	ͨ��ָ���Ӹ�ֵ��3������:
	1. ��������
	2. ������ϵ
	3. ͨ��*�����ڴ�
	*/

	int b = get_b1();
	printf("b1 = %d\n", b);	//b1 = 10

	get_b2(b);
	printf("b2 = %d\n", b);	//b2 = 10

	//�����ͨ���βθı�ʵ�ε��ڴ�����(ֵ),����ͨ����ַ����
	//ʵ��,�β�
	get_b3(&b);	//�ں�������ʱ,������ϵ
	printf("b3 = %d\n", b);	//b3 = 99

	int a1 = 0;
	int a2 = 0;
	int a3 = 0;
	get_a_3(&a1, &a2, &a3);
	printf("\na1 = %d. a2 = %d, a3 = %d\n", a1, a2, a3);

	printf("\n");
	system("pause");
	return 0;
}

void fun2(int* p)
{
	p = 0xaabb;
	printf("fun2 p = %p\n", p);
}

void fun3(int** p)
{
	*p = 0xaabb;
	printf("fun3 p = %p\n", p);
	printf("fun3 *p = %p\n", *p);
}

int main(void)
{
	//һ������,Ӧ�ö���һ����ô�����͵�ָ��,�������ĵ�ַ
	//��ԭ�����ͻ����ϼ�һ��*
	//int a = 10;
	//int* p = &a;
	//int** q = &p;

	//int******** m = NULL;
	//int********* n = &m;

	int* p = 0x1122;
	printf("p1 = %p\n\n", p);

	fun2(p);	//ֵ����
	printf("p2 = %p\n\n", p);

	fun3(&p);	//��ַ����
	printf("p3 = %p\n", p);

	printf("\n");
	system("pause");
	return 0;
}