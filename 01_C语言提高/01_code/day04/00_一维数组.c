#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

int main(void)
{
	//int b[];	//error	不指定元素个数,必须初始化
	int c[100] = { 1, 2, 3, 4 };	//没有赋值的都为0

	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };	//8个
	int a[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };	//8个
	//sizeof()测变量所占的空间(变量所对应类型的空间)

	int n = 0;
	//sizeof(a) = 4 * 8 = 32	数组类型: 由"元素个数"和"元素类型"决定	int [8]
	//sizeof(a[0]) = 4	首元素大小,每个元素4字节
	n = sizeof(a) / sizeof(a[0]);	//n = 8

	for (int i = 0; i < n; ++i)
	{
		//*(a+i): a+i代表第i个元素的地址,*(a+i)代表指针指向的内存
		//[] * 等价
		//printf("%d ", a[i]);
		printf("%d ", *(a + i));
	}
	printf("\n");

	//数组类型
	//a : 数组首元素地址
	//&a: 整个数组的首地址,和数组首元素地址一样,但是,二者步长不一致
	printf("a : %p, a+1 : %p\n", a, a + 1);	//+4字节
	printf("&a: %p, &a+1: %p\n\n", &a, &a + 1);	//+32字节

	//数组类型: 由"元素个数"和"元素类型"决定	int [8]
	//通过typedef定义一个数组类型
	//有typedef是类型,没有typedef是变量
	typedef int A[8];	//代表数组类型,它是类型,不是变量
	//typedef int(A)[8];
	A b;	//int b[8];	去了typedef,b替换到A的位置

	for (int i = 0; i < 8; ++i)
	{
		b[i] = i;
	}

	for (int i = 0; i < 8; ++i)
	{
		//printf("%d ", b[i]);
		printf("%d ", *(b + i));
	}
	printf("\n");

	printf("b : %p, b+1 : %p\n", b, b + 1);	//+4字节
	printf("&b: %p, &b+1: %p\n", &b, &b + 1);	//+32字节

	printf("\n");
	system("pause");
	return 0;
}