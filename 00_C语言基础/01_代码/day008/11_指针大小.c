/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-28 22:14
 * Last modified  : 2020-07-28 22:14
 * Filename       : 11_指针大小.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	//1. 32位编译器用32位大小(4字节)保存地址
	//2. 64位编译器用64位大小(8字节)保存地址
	
	int a = sizeof(int *);
	int b = sizeof(char *);

	double **************************************p;
	int c = sizeof(p);
	printf("a = %d, b = %d, c = %d\n", a, b, c);

	return 0;
}
