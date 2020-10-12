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
1. 函数的参数是变量,可以是函数指针变量吗?
2. 框架,固定,用这种方式实现多态
3. 多态,多种形态,调用同一接口,不一样的结果
*/
void fun1(int x, int y, int(*p)(int a, int b))
{
	printf("fun1==================\n");

	int n = p(x, y);	//回调函数
	printf("n = %d\n", n);
}

typedef int(*P)(int a, int b);	//函数指针类型
void fun2(int x, int y,	P p)
{
	printf("fun2==================\n");

	int n = p(x, y);	//回调函数
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