#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>	//strcpy()

/*
1. 结构体类型定义
2. 结构体变量定义
3. 结构体变量的初始化
4. typedef 修改类型名
5. 点运算符和指针法操作结构体
6. 结构体也是一种数据类型,复合类型,自定义类型
*/

//1. 结构体类型定义
//struct关键字
//struct Teacher合在一起才是类型
//{}后面有分号
struct Teacher1
{
	char name[10];
	int age;
};

//2. 结构体变量定义
//1) 先定义类型,后定义变量(常用)
struct Teacher1 t1;	//全局变量
//2) 定义类型同时定义变量
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

//3. 结构体变量的初始化
//定义变量时直接初始化,通过{}
struct Teacher1 t5 = { "teacher5", 55 };

//4. typedef 修改类型名
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

	//5. 点运算符和指针法操作结构体
	struct Teacher1 t2;	//局部变量
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