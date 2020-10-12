#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. 指针函数
2. ()优先级比*高
3. 它是函数,返回值是指针类型的函数
4. 返回指针类型的函数
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
	1. 函数指针
	2. 它是指针,指向函数的指针
	3. 定义函数指针变量有3种方式:
		1) 先定义函数类型,根据类型定义指针变量(不常用)
			有typedef是类型,没有是变量
			typedef int FUN(int a);	//FUN函数类型
			FUN* p1 = NULL;	//函数指针变量

		2) 先定义函数指针类型,根据类型定义指针变量(常用)
			typedef int (*P_FUN)(int a);	//P_FUN,函数指针类型
			P_FUN p2 = fun;	//p2指向fun函数

		3) 直接定义函数指针变量(常用)
			int(*p3)(int a) = fun;

			int(*p4)(int a);
			p4 = fun;
	*/

	//1) 先定义函数类型, 根据类型定义指针变量(不常用)
	//有typedef是类型, 没有是变量
	typedef int FUN(int a);	//FUN函数类型
	FUN* p1 = NULL;	//函数指针变量
	p1 = fun;	//p1指向fun函数
	fun(5);	//传统调用
	p1(6);	//函数指针变量调用方法

	//2) 先定义函数指针类型,根据类型定义指针变量(常用)
	typedef int (*P_FUN)(int a);	//P_FUN,函数指针类型
	P_FUN p2 = fun;	//p2指向fun函数
	p2(7);

	//3) 直接定义函数指针变量(常用)
	int(*p3)(int a) = fun;
	p3(8);

	int(*p4)(int a);
	p4 = fun;
	p4(9);

	printf("\n");
	system("pause");
	return 0;
}