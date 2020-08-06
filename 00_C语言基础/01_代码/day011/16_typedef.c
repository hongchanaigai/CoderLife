/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-06 19:07
 * Last modified  : 2020-08-06 19:07
 * Filename       : 16_typedef.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

struct Test
{
	int a;
};

//定义一个结构体变量
struct Test obj;

//给struct Test2类型起一个别名叫Test2
typedef struct Test2
{
	int a;
}Test2;

Test2 tmp;

int main()
{
	//1. typedef给一个已存在的类型起一个别名
	//2. typedef不能创建新类型

	//给int起一个别名,叫int64
	typedef int int64; //有分号

	int64 a; //int a; //宏定义发生在预处理,typedef是在编译阶段

	return 0;
}
