#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>	//memset()

//����ṹ������ʱ��Ҫֱ�Ӹ��ṹ���Ա��ֵ
//�ṹ��ֻ��һ������,��û�з���ռ�
//ֻ�и��������Ͷ������ʱ,�ŷ���ռ�,�пռ����ܸ�ֵ
typedef struct Teacher
{
	char name[10];
	int age;
}Teacher;

void copyTeacher(Teacher to, Teacher from)
{
	to = from;
	printf("copyTeacher: %s, %d\n", to.name, to.age);
}

void copyCD(int to, int from)
{
	to = from;
}

void copyTeacher2(Teacher *to, Teacher *from)
{
	*to = *from;
	printf("copyTeacher2: %s, %d\n", to->name, to->age);
}

int main(void)
{
	Teacher t1 = { "teacher1", 11 };
	//��ͬ���͵������ṹ�����,�����໥��ֵ
	//��t1��Ա�����ڴ��ֵ,������t2��Ա�������ڴ�
	//t1��t2û�й�ϵ
	Teacher t2 = t1;
	printf("%s, %d\n\n", t2.name, t2.age);

	int a = 10;
	int b = a;	//a��ֵ����b,����û�й�ϵ

	Teacher t3;
	memset(&t3, 0, sizeof(Teacher));
	copyTeacher(t3, t1);	//t1������t3
	printf("main: %s, %d\n\n", t3.name, t3.age);

	int c = 10;
	int d = 0;
	copyCD(c, d);	//c��ֵ��d
	printf("main: c = %d, d = %d\n\n", c, d);

	Teacher t4;
	memset(&t4, 0, sizeof(Teacher));
	copyTeacher2(&t4, &t1);	//t1������t4
	printf("main: %s, %d\n", t4.name, t4.age);

	printf("\n");
	system("pause");
	return 0;
}