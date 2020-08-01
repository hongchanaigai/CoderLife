/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-01 19:13
 * Last modified  : 2020-08-01 19:13
 * Filename       : 13_字符指针数组.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

//void func(int a[10])
//coid func(int a[])
void func(int *a)
{
}

//void print_array(char *p[], int n)
void print_array(char **p, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%s\n", p[i]);
	}
}

int main()
{
	int a[10];
	func(a);
	
	char *p[] = {"hello", "abc", "huang"};
	int n = sizeof(p) / sizeof(*p);

	print_array(p, n);

	return 0;
}

int main01()
{
	char *p1 = "hello";
	char *p2 = "abc";
	char *p3 = "huang";

	char *p[] = {"hello", "abc", "huang"};
	int n = sizeof(p) / sizeof(*p);
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%s\n", p[i]);
	}

	return 0;
}
