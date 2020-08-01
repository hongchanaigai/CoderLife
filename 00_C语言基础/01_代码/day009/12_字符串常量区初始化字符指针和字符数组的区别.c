/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-01 18:01
 * Last modified  : 2020-08-01 18:01
 * Filename       : 12_字符串常量区初始化字符指针和字符数组的区别.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main()
{
	//1. p指针保存了"hello"的地址
	//2. 指针所指向的内存不能修改
	char *p = "hello";

	//1. 把"hello"一个一个字符放在buf数组中
	//2. 数组的元素可以修改
	char buf[] = "hello";

	return 0;
}
