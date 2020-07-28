/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 17:41
 * Last modified  : 2020-07-20 17:41
 * Filename       : 06_practice.c
 * Description    : 定义一个数组,有10个元素,分别赋值为1~10,顺便打印每个元素的值
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a[10];
	int i;

	for(i = 0; i < 10; ++i)
	{
		a[i] = i + 1;
	}

	for(i = 0; i < 10; ++i)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}

	return 0;
}
