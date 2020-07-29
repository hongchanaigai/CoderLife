/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-29 18:15
 * Last modified  : 2020-07-29 18:15
 * Filename       : 22_作业1_找出数组第二大的数.c
 * Description    : 有个数组,找出第二大的数(不能排序后打印)
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a[] = {5, 100, 32, 45, 21, 67, 32, 68, 41, 99, 13, 71};
	int na = sizeof(a) / sizeof(*a); //数组元素个数
	int i, tmp, max, second; //second用来保存第二大的数

	max = 0; //初始化为0
	second = 0; //初始化为0

	//找出最大的元素,存放在max
	for(i = 0; i < na; ++i)
	{
		if(*(a+i) > max)
		{
			max = *(a+i);
		}
	}

	//找出第二大的数,存放在second
	for(i = 0; i < na; ++i)
	{
		if(max > *(a+i) && second < *(a+i))
		{
			second = *(a+i);
		}
	}

	printf("second max number is %d\n", second);

	return 0;
}
