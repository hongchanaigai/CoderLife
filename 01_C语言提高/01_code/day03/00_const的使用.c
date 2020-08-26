#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

typedef struct MyStruct
{
	int a;
	int b;
}MyStruct;

void fun1(MyStruct* p)
{
	//指针能变
	//p = NULL;	//ok
	//指针指向的内存能变
	p->a = 10;	//ok
}

void fun2(MyStruct const* p)
{
	//指针能变
	//p = NULL;	//ok
	//指针指向的内存不能变
	//p->a = 10;	//error
}

void fun3(MyStruct* const p)
{
	//指针不能变
	//p = NULL;	//error
	//指针指向的内存能变
	p->a = 10;	//ok
}

void fun4(MyStruct const* const p)
{//只读
	//指针不能变
	//p = NULL;	//error
	//指针指向的内存不能变
	//p->a = 10;	//error
	MyStruct tmp;
	tmp.a = p->a;
}

int main(void)
{
#if 0
	//const修饰一个变量为只读
	const int a = 10;
	//a = 100;	//error

	//指针变量,指针指向的内存,是2个不同概念
	char buf[] = "afgsihefoqejfrp";

	//从左往右看,跳过类型,看修饰那个字符
	//如果是*,说明指针指向的内存不能改变
	//如果是指针变量,说明指针的指向不能改变
	const char* p1 = buf;	//等价于char const* p1 = buf;
	//p1[1] = '1';	//error
	p1 = "gsiafhojwceiwejif";	//ok
	
	char* const p2 = buf;
	p2[1] = '1';	//ok
	//p2 = "caifhcoajdekoeqkc";	//error

	const char* const p3 = buf;
	//p3为只读,指向不能改变,指向的内存也不能改变
#endif // 0

	//如何引用另外一个.c中的const变量,了解
	extern const int a;	//只能声明,不能再赋值

	//const修饰的变量,定义时初始化
	const int b = 10;
	//b = 100;	//error
	int* p = &b;
	*p = 100;	//ok,间接修改const变量b的值
	printf("*p = %d, b = %d\n", *p, b);

	printf("\n");
	system("pause");
	return 0;
}