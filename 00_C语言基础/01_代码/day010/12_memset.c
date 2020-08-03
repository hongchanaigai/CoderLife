/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-03 17:34
 * Last modified  : 2020-08-03 17:34
 * Filename       : 12_memset.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //memst()

int main()
{
	int b[10] = {0};

	//处理一些代码,把b内部的元素改了
	
	//b[10] = {0}; //error
	
	int i = 0;
	int n = sizeof(b) / sizeof(b[0]);
	for(i = 0; i < n; ++i)
	{
		b[i] = 0;
	}

	memset(b, 0, sizeof(b));


	char str[10];
	memset(str, 'a', sizeof(str));
	for(i = 0; i < 10; ++i)
	{
		printf("%c ", str[i]);
	}
	printf("\n");

	return 0;
}

int main01()
{
	int a;
	memset(&a, 0, sizeof(a)); //常用
	printf("a = %d\n", a);

	memset(&a, 10, sizeof(a));
	printf("a1 = %d\n", a);

	//中间参数虽然是整型,但是以字符处理
	memset(&a, 97, sizeof(a));
	printf("a2 = %c\n", a);

	int b[10];
	memset(b, 0, sizeof(b));
	memset(b, 0, sizeof(int) * 10);

	return 0;
}
