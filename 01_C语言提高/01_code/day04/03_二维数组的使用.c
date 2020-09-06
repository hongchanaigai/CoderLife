#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

int main00(void)
{
	int a1[3][4] = {
		{1, 2, 3, 4},
		{2, 3, 4, 5},
		{3, 4, 5, 6}
	};
	
	int a2[3][4] = { 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6 };

	int a3[][4] = { 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6 };
	
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			printf("%d ", a3[i][j]);
		}
		printf("\n");
	}

	//二维数组数组名代表第0行的首地址(区别于第0行首元素地址,虽然值一样)
	//二者步长不一致
	printf("\na3: %p, a3+1: %p\n", a3, a3 + 1);	//+16字节

	printf("\n*(a3+0)  : %p\n", *(a3 + 0));	//第0行首元素地址
	printf("*(a3+1)  : %p\n", *(a3 + 1));	//第1行首元素地址
	printf("*(a3+0)+1: %p\n", *(a3 + 0) + 1);	//第0行第二个元素地址

	printf("\na3[0]: %p, a3[0+1]: %p\n", a3[0], a3[0 + 1]);
	printf("a3[0]: %p, a3[0]+1: %p\n", a3[0], a3[0] + 1);

	int a[][4] = { 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6 };
	//a	:			代表第0行首地址
	//a+i:			代表第i行首地址,等价于&a[i]
	//*(a+i):		代表第i行首元素的地址,等价于a[i]
	//*(a+i)+j:		代表第i行第j列元素的地址,等价于&a[i][j]
	//*(*(a+i)+j):	代表第i行第j列元素的值,等价于a[i][j]

	printf("\n");
	system("pause");
	return 0;
}

void print_a(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}

int main01(void)
{
	int a[3][4] = { 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6 };

	//int n = sizeof(a) / sizeof(a[0]);	//n = (4*3*4) / (4*1*4) = 3
	//int n = sizeof(a);	//n = 4*3*4 = 48
	int n = sizeof(a) / sizeof(int);	//n = (4*3*4) / 4 = 12
	//int n = sizeof(a) / sizeof(a[0][0]);	//n = (4*3*4) / 4 = 12

	print_a((int*)a, n);

	printf("\n");
	system("pause");
	return 0;
}


int main02(void)
{
	int a[][8] = { 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6 };
	//3个a[4]的一维数组

#if 0
	//定义数组指针变量
	//指向一维数组的整个数组首地址
	int(*p)[8];
	//p = &a;	//整个二维数组的首地址,p = a
	p = a;	//第0行首地址,p等价于二维数组名
	printf("p: %p, p+1: %p\n", p, p + 1);	//4 * 8 = 32个字节
#endif // 0

	//定义数组指针类型,再定义变量
	typedef int(*P)[8];
	P p;
	p = a;

	int ni = sizeof(a) / sizeof(a[0]);	//ni = 2
	int nj = sizeof(a[0]) / sizeof(int);	//nj = 8
	//等价于int nj = sizeof(a[0]) / sizeof(a[0][0]);	//nj = 8

	for (int i = 0; i < ni; ++i)
	{
		for (int j = 0; j < nj; ++j)
		{
			//printf("%d ", p[i][j]);
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}

	printf("\n");
	system("pause");
	return 0;
}

int main03(int argc, char* argv[])
{
	int a[10] = { 0 };
	//测一维数组长度: sizeof()首行首元素的地址
	printf("sizeof(a)     : %d, sizeof(&a)   : %d\n", sizeof(a), sizeof(&a));
	//sizeof(a): 4*10 = 40, sizeof(&a): 4

	int b[2][10] = { 0 };
	printf("sizeof(b[0])  : %d, sizeof(&b[0]): %d\n", sizeof(b[0]), sizeof(&b[0]));
	printf("sizeof(*(b+0)): %d, sizeof(b+0)  : %d\n", sizeof(*(b + 0)), sizeof(b + 0));

	printf("\n");
	system("pause");
	return 0;
}

//数组做形参都会退化成指针,指针步长不一定一样
void print_array1(int a[3][4])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}

//步长: a+1, 一行: 4*4 = 16字节
void print_array2(int a[][4])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}

//步长: a+1: 4字节
void print_array3(int** a)
{

}

//数组指针
void print_array4(int(*a)[4])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}

//数组指针类型
typedef int(*A)[4];
void print_array5(A a)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	printf("print_array1:\n");
	print_array1(a);
	printf("\nprint_array2:\n");
	print_array2(a);
	printf("\nprint_array4:\n");
	print_array2(a);
	printf("\nprint_array5:\n");
	print_array2(a);

	printf("\n");
	system("pause");
	return 0;
}