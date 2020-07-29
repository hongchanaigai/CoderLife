/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 18:57
 * Last modified  : 2020-07-20 19:00
 * Filename       : 10_array_name.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a[10];
	//1. 数组名是常量,不能修改
	//a = 10;	//error
	
	//2. 数组名是数组收元素地址
	printf("a = %p, &a[0] = %p\n", a, &a[0]);

	//3. sizeof(数组名)测数组总大小:10 * 4 = 40
	printf("sizeof(a) = %lu\n", sizeof(a));

	//4. 元素个数: 总大小/某个元素大小
	int n = sizeof(a) / sizeof(a[0]);
	printf("n = %d\n", n);

	return 0;
}
