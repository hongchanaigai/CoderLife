#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

//�ṹ�����Ͷ�������,�ڲ���Ա�������ڴ沼���Ѿ�ȷ��
typedef struct teacher
{
	/*char name[4];*/	//4
	char name[64];	//64
	int age;	//4
	int id;	//4
}teacher;

int main(void)
{
	teacher t1;
	teacher* p = NULL;
	p = &t1;

	int n1 = (int)(&p->age) - (int)p;	//����ڽṹ���׵�ַ
	printf("n1 = %d\n", n1);

	int n2 = (int)&((teacher*)0)->age;	//����0��ַ��ƫ����
	printf("n2 = %d\n", n2);

	printf("\n");
	system("pause");
	return 0;
}