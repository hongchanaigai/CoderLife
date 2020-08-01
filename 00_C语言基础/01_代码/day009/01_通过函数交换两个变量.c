/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-29 20:57
 * Last modified  : 2020-07-29 21:28
 * Filename       : 01_通过函数交换两个变量.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

void swap(int m, int n)
{
	int tmp;
	tmp = m;
	m = n;
	n = tmp;
	printf("m = %d, n = %d\n", m, n);
}

void swap2(int *m, int *n)
{
	int tmp;
	tmp = *m;
	*m = *n;
	*n = tmp;
	printf("*m = %d, *n = %d\n", *m, *n);
}

int main()
{
	int a = 11;
	int b = 22;

	//swap(a, b); //值传递,不管这个变量什么类型,只要是变量本身传递,就是值传递
	swap2(&a, &b);
	printf("a = %d, b = %d\n", a, b);

	return 0;
}
