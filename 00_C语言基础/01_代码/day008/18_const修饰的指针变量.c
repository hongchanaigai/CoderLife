/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-29 17:26
 * Last modified  : 2020-07-29 17:26
 * Filename       : 18_const修饰的指针变量.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	//1. 指针变量
	//2. 指针所指向的空间
	
	int a = 10;
	int *p1 = &a;
	*p1 = 100; //等价于操作a,*p1操作指针所指向的内存
	p1 = NULL; //操作指针变量

	//const修饰*,代表指针所指向的内存是只读的
	const int *p2 = &a;
	//*p2 = 100; //error
	p2 = NULL; //ok

	int const *p3 = &a;
	//*p3 = 100; //error
	p3 = NULL; //ok

	//const修饰指针变量,代表指针变量的值为只读
	int * const p4 = &a;
	*p4 = 100; //ok
	//p4 = NULL; //error
	
	//只读,不论指针变量,还是指向的内存都不允许修改
	const int * const p5 = &a;
	//*p5 = 100; //error
	//p5 = NULL; //error

	return 0;
}
