#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. ָ�뺯��
2. ()���ȼ���*��
3. ���Ǻ���,����ֵ��ָ�����͵ĺ���
4. ����ָ�����͵ĺ���
*/
int* fun1()
{
	int* p = (int*)malloc(sizeof(int));

	return p;
}

int fun(int a)
{
	printf("\na ================== %d", a);
	return 0;
}

int main(void)
{
	/*
	1. ����ָ��
	2. ����ָ��,ָ������ָ��
	3. ���庯��ָ�������3�ַ�ʽ:
		1) �ȶ��庯������,�������Ͷ���ָ�����(������)
			��typedef������,û���Ǳ���
			typedef int FUN(int a);	//FUN��������
			FUN* p1 = NULL;	//����ָ�����

		2) �ȶ��庯��ָ������,�������Ͷ���ָ�����(����)
			typedef int (*P_FUN)(int a);	//P_FUN,����ָ������
			P_FUN p2 = fun;	//p2ָ��fun����

		3) ֱ�Ӷ��庯��ָ�����(����)
			int(*p3)(int a) = fun;

			int(*p4)(int a);
			p4 = fun;
	*/

	//1) �ȶ��庯������, �������Ͷ���ָ�����(������)
	//��typedef������, û���Ǳ���
	typedef int FUN(int a);	//FUN��������
	FUN* p1 = NULL;	//����ָ�����
	p1 = fun;	//p1ָ��fun����
	fun(5);	//��ͳ����
	p1(6);	//����ָ��������÷���

	//2) �ȶ��庯��ָ������,�������Ͷ���ָ�����(����)
	typedef int (*P_FUN)(int a);	//P_FUN,����ָ������
	P_FUN p2 = fun;	//p2ָ��fun����
	p2(7);

	//3) ֱ�Ӷ��庯��ָ�����(����)
	int(*p3)(int a) = fun;
	p3(8);

	int(*p4)(int a);
	p4 = fun;
	p4(9);

	printf("\n");
	system("pause");
	return 0;
}