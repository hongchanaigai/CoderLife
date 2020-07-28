/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 19:33
 * Last modified  : 2020-07-20 19:33
 * Filename       : 13_数组的翻转.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(a) / sizeof(a[0]);	//元素个数
	int i = 0;	//首元素下标
	int j = n - 1;	//尾元素下标
	int tmp;

	while(i < j)
	{
		//交换a[i]和a[j]
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;

		++i;	//从左往右走
		--j;	//从右往左走
	}

	for(i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
