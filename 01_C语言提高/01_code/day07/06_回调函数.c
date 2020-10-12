#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b)
{
	return a + b;
}

int minus(int a, int b)
{
	return a - b;
}

/*
1. �����Ĳ����Ǳ���,�����Ǻ���ָ�������?
2. ���,�̶�,�����ַ�ʽʵ�ֶ�̬
3. ��̬,������̬,����ͬһ�ӿ�,��һ���Ľ��
*/
void fun1(int x, int y, int(*p)(int a, int b))
{
	printf("fun1==================\n");

	int n = p(x, y);	//�ص�����
	printf("n = %d\n", n);
}

typedef int(*P)(int a, int b);	//����ָ������
void fun2(int x, int y,	P p)
{
	printf("fun2==================\n");

	int n = p(x, y);	//�ص�����
	printf("n = %d\n", n);
}

int main(void)
{
	fun1(1, 2, add);

	fun1(10, 2, minus);
	
	fun2(10, 2, minus);

	printf("\n");
	system("pause");
	return 0;
}