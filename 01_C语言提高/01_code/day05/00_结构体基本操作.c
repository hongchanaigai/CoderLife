#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>	//strcpy()

/*
1. �ṹ�����Ͷ���
2. �ṹ���������
3. �ṹ������ĳ�ʼ��
4. typedef �޸�������
5. ���������ָ�뷨�����ṹ��
6. �ṹ��Ҳ��һ����������,��������,�Զ�������
*/

//1. �ṹ�����Ͷ���
//struct�ؼ���
//struct Teacher����һ���������
//{}�����зֺ�
struct Teacher1
{
	char name[10];
	int age;
};

//2. �ṹ���������
//1) �ȶ�������,�������(����)
struct Teacher1 t1;	//ȫ�ֱ���
//2) ��������ͬʱ�������
struct Teacher2
{
	char name[10];
	int age;
}t3 = { "teacher3", 33 };

struct
{
	char name[10];
	int age;
}t4 = { "teacher4", 44 };

//3. �ṹ������ĳ�ʼ��
//�������ʱֱ�ӳ�ʼ��,ͨ��{}
struct Teacher1 t5 = { "teacher5", 55 };

//4. typedef �޸�������
typedef struct Teacher3
{
	char name[10];
	int age;
}Teacher3;

struct Teacher3 t6;
Teacher3 t7;

int main(void)
{
	printf("%s, %d\n", t5.name, t5.age);

	//5. ���������ָ�뷨�����ṹ��
	struct Teacher1 t2;	//�ֲ�����
	strcpy(t2.name, "teacher2");
	t2.age = 22;
	printf("%s, %d\n", t2.name, t2.age);

	struct Teacher1* p = NULL;
	struct Teacher1 t8;
	p = &t8;
	strcpy(p->name, "teacher8");
	p->age = 88;
	printf("%s, %d\n", p->name, p->age);

	printf("\n");
	system("pause");
	return 0;
}