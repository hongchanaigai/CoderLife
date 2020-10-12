#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

typedef struct A
{
	int a;
	int b;
	char* p;
}A;

/*
1. 结构体可以嵌套另外一个结构体的任何类型变量
2. 结构体嵌套本结构体普通变量(不可以,本结构体的类型大小无法确定)
	类型本质: 固定大小内存块别名
3. 结构体嵌套本结构体指针变量(可以,本结构体的类型大小可以确定)
	指针变量的空间可以确定
	指针变量: 32位,4字节	64位,8字节
*/
typedef struct B
{
	int a;
	A tmp1;	//ok
	A* p1;	//ok

	//struct B tmp2;	//error
	struct B* p2;	//ok
}B;

int main(void)
{
	printf("\n");
	system("pause");
	return 0;
}