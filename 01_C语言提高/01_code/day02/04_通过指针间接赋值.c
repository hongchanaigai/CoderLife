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
	*b = 99;	//通过*操作内存
}

void get_a_3(int* a1, int* a2, int* a3)
{
	*a1 = 1;
	*a2 = 2;
	*a3 = 3;
}

int main00(void)
{
	//间接赋值是指针存在的最大意义

	//两个变量: 一个普通变量,一个指针变量
	int a = 100;
	int* p = NULL;
	//建立关系: 指针指向谁,就把谁的地址赋值给指针变量
	p = &a;
	//通过*操作内存
	*p = 22;

	/*
	通过指针间接赋值的3个条件:
	1. 两个变量
	2. 建立关系
	3. 通过*操作内存
	*/

	int b = get_b1();
	printf("b1 = %d\n", b);	//b1 = 10

	get_b2(b);
	printf("b2 = %d\n", b);	//b2 = 10

	//如果想通过形参改变实参的内存内容(值),必须通过地址传递
	//实参,形参
	get_b3(&b);	//在函数调用时,建立关系
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
	//一个变量,应该定义一个怎么样类型的指针,保存它的地址
	//在原来类型基础上加一个*
	//int a = 10;
	//int* p = &a;
	//int** q = &p;

	//int******** m = NULL;
	//int********* n = &m;

	int* p = 0x1122;
	printf("p1 = %p\n\n", p);

	fun2(p);	//值传递
	printf("p2 = %p\n\n", p);

	fun3(&p);	//地址传递
	printf("p3 = %p\n", p);

	printf("\n");
	system("pause");
	return 0;
}