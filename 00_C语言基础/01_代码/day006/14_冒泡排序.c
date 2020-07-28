/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 19:41
 * Last modified  : 2020-07-20 20:04
 * Filename       : 14_冒泡排序.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a[] = {1, -1, 2, -2, 3, -3, 4, -4, 5, -5};
	int n = sizeof(a) / sizeof(a[0]);
	int i, j, tmp;

	printf("before: ");
	for(i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	//冒泡排序
	/*
	 1. i = 0, i < 9
	    j = 0, j < 9, a[0], a[1]
	    j = 1, j < 9, a[1], a[2]
	    j = 2, j < 9, a[2], a[3]
	    ......
	    j = 8, j < 9, a[8], a[9]
	    j = 9, j < 9, 退出循环for(j = 0; j < n-1-i; ++j)

	 2. i = 1, i < 9
	    j = 0, j < 8, a[0], a[1]
	    j = 1, j < 8, a[1], a[2]
	    ......
	    j = 7, j < 8, a[7], a[8]
	    j = 8, j < 8, 退出循环for(j = 0; j < n-1-i; ++j)

	 ......
	 */
	for(i = 0; i < n-1; ++i)
	{
		for(j = 0; j < n-1-i; ++j)
		{
			if(a[j] > a[j+1])  //相邻两个元素比较,大于交换
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}

	printf("after : ");
	for(i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
