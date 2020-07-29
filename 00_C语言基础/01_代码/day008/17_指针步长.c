/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-29 17:17
 * Last modified  : 2020-07-29 17:17
 * Filename       : 17_指针步长.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	//1. 指针的加法,不是传统的加法
	//2. 步长由指针指向的数据类型决定
	int a;
	int *p = &a;
	printf("p: %d, p+1: %d\n", p, p+1);

	char b;
	char *q = &b;
	printf("q: %d, q+1: %d\n", q, q+1);

	return 0;
}
