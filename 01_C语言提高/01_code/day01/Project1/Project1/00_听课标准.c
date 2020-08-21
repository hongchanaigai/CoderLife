#include <stdio.h>
#include <stdlib.h> //system()

int main00(void)
{
	int a[] = { 10, 7, 1, 9, 4, 6, 7, 3, 2, 0 };
	int n = sizeof(a) / sizeof(a[0]); //元素个数
	int i = 0;

	printf("before sort: \n");
	for (i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	//选择法排序
	/*
	10, 7, 1, 9, 4, 6, 7, 3, 2, 0
	7, 10,(10 > 7交换)
	1, 10, 7, 9, 4, 6, 7, 3, 2,(7 > 1交换)
	0, 10, 7, 9, 4, 6, 7, 3, 2, 1(1 > 0交换)
	把最小的放在最前面
	*/
	int j = 0;
	int tmp = 0;
	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (a[i] > a[j]) //升序
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	printf("after sort: \n");
	for (i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	//如何看懂带算法的程序
	/*
	1.流程
	2.每个语句功能
	3.试数
	4.调试
	5.模仿改
	6.不看代码写
	*/

	printf("\n");
	system("pause");
	return 0;
}


//如果数组作为函数参数,数组形参会退化成指针,32位系统4字节
//void print_array(int a[10], int n) //打印数组元素
//void print_array(int a[], int n) //打印数组元素
void print_array(int* a, int n) //打印数组元素
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void sort_array(int* a, int n) //选择排序
{
	int i, j, tmp;
	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (a[i] > a[j]) //升序
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int main(void)
{
	int a[] = { 10, 7, 1, 9, 4, 6, 7, 3, 2, 0 };
	int n = sizeof(a) / sizeof(a[0]); //元素个数
	printf("n = %d\n", n);

	//排序前打印
	printf("before sort: \n");
	print_array(a, n);

	//选择排序
	sort_array(a, n);

	//排序后打印
	printf("after sort: \n");
	print_array(a, n);

	printf("\n");
	system("pause");
	return 0;
}