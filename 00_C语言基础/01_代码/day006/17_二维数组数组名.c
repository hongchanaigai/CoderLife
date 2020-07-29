/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 20:44
 * Last modified  : 2020-07-20 20:44
 * Filename       : 17_二维数组数组名.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a[5][10];

	//1. 数组名是常量,不能修改
	//a = 10;	//error
	
	//2. sizeof(数组名),测数组的总大小: 5 * int[10] = 5 * 4 * 10 = 200
	printf("sizeof(a) = %lu\n", sizeof(a));

	//3. sizeof(a[0]),测的是第0个元素的大小: int[10] = 4 * 10 = 40
	printf("sizeof(a[0]) = %lu\n", sizeof(a[0]));

	//4. sizeof(a[0][0]),测得是第0行第0列元素的大小: int = 4
	printf("sizeof(a[0][0]) = %lu\n", sizeof(a[0][0]));

	//5. 求行数(元素个数):总大小/每个元素大小
	int m = sizeof(a) / sizeof(a[0]);
	printf("行数 = %d\n", m);

	//6. 求列数
	int n = sizeof(a[0]) / sizeof(a[0][0]);
	printf("列数 = %d\n", n);

	//7. 行 * 列
	int cout = sizeof(a) / sizeof(a[0][0]);
	printf("总个数 = %d\n", cout);

	return 0;
}
