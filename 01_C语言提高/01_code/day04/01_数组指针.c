#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

//argc: 传参数的个数(包括可执行程序)
//argv: 指针数组,指向输入的参数
int main(int argc, char* argv[])
{
	//指针数组,数组指针

#if 0
	//1. 指针数组,它是数组,每个元素都是指针
	//		[] 的优先级比 * 高
	char* a[] = { "aaaaa", "bbbbb", "ccccc" };

	printf("argc = %d\n", argc);

	for (int i = 0; i < argc; ++i)
	{
		printf("argv[%d] = [%s]\n", i, argv[i]);
	}
#endif	//0

#if 0
	//2. 数组指针,它是指针,指向一个数组的指针
	//		数组指针,指向的是一维数组的整个数组,而不是首元素的地址
	//		定义数组指针变量
	//			1) 先定义数组类型,根据数组类型定义指针变量
	typedef int(A)[10];	//A数组类型,[10]代表步长
	A* p = NULL;	//p数组指针类型变量

	int a[10] = { 0 };

	//p = a;	//warning	a代表首元素地址, a 和 &a 一样,最终也是当做 &a
	p = &a;	//&a 代表整个数组首地址

	printf("p: %p, p+1: %p\n\n", p, p + 1);

	for (int i = 0; i < 10; ++i)
	{
		//a[]
		//p = &a
		//*p = *&a --> a
		(*p)[i] = i;
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", (*p)[i]);
	}
	printf("\n");
#endif	//0

#if 0
	//			2) 先定义数组指针类型,根据指针类型定义变量
	//和指针数组写法很类似,多了()
	//() 和 [] 优先级一样,从左往右
	//() 有指针,它是一个指针, [] 
	//指向数组的指针,它有typedef,所以它是一个数组指针类型
	typedef int(*P)[10];
	P ptr;	//数组指针类型

	int a[10] = { 0 };
	ptr = &a;

	for (int i = 0; i < 10; ++i)
	{
		(*ptr)[i] = i + 1;
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", (*ptr)[i]);
	}
	printf("\n");
#endif	//0

	//			3) 直接定义数组指针变量
	//和指针数组写法很类似,多了()
	//() 和 [] 优先级一样,从左往右
	//() 有指针,它是一个指针, [] 
	//指向数组的指针,它没有typedef,所以它是一个数组指针变量
	int(*ptr)[10];	//数组指针变量

	int a[10] = { 0 };
	ptr = &a;

	for (int i = 0; i < 10; ++i)
	{
		(*ptr)[i] = i + 2;
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", (*ptr)[i]);
	}
	printf("\n");

	printf("\n");
	system("pause");
	return 0;
}