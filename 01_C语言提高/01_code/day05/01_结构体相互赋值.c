#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>	//memset()

//定义结构体类型时不要直接给结构体成员赋值
//结构体只是一个类型,还没有分配空间
//只有根据其类型定义变量时,才分配空间,有空间后才能赋值
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
	//相同类型的两个结构体变量,可以相互赋值
	//把t1成员变量内存的值,拷贝给t2成员变量的内存
	//t1和t2没有关系
	Teacher t2 = t1;
	printf("%s, %d\n\n", t2.name, t2.age);

	int a = 10;
	int b = a;	//a的值给了b,二者没有关系

	Teacher t3;
	memset(&t3, 0, sizeof(Teacher));
	copyTeacher(t3, t1);	//t1拷贝给t3
	printf("main: %s, %d\n\n", t3.name, t3.age);

	int c = 10;
	int d = 0;
	copyCD(c, d);	//c的值给d
	printf("main: c = %d, d = %d\n\n", c, d);

	Teacher t4;
	memset(&t4, 0, sizeof(Teacher));
	copyTeacher2(&t4, &t1);	//t1拷贝给t4
	printf("main: %s, %d\n", t4.name, t4.age);

	printf("\n");
	system("pause");
	return 0;
}