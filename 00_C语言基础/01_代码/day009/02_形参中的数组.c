/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-30 17:49
 * Last modified  : 2020-07-30 17:49
 * Filename       : 02_形参中的数组.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

//1. 形参中的数组,不是数组,它是普通指针变量
//2. 形参数组: int a[1000],int a[],int *a对编译器而言,没有任何区别,编译器都是当做int *处理
//3. 形参中的数组和非形参数组区别:形参中的数组是指针变量,非形参中的数组就是数组
//void print_array(int a[1000])
//void print_array(int a[])
void print_array(int *a)
{
	int i;
	//64位系统,sizeof(a),a是指针变量,结果为8
	//sizeof(a[0]),第0个元素,是int类型,结果为4
	int n = sizeof(a) / sizeof(a[0]); //只会打印两个值
	printf("sizeof(a) = %d\n", sizeof(a));
	printf("sizeof(a[0]) = %d\n", sizeof(a[0]));

	for(i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");


	//a = NULL; //ok,形参中的数组,不是数组,它是普通指针变量
}

void print_array2(int *a, int n)
{
	int i;

	for(i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = {1, -2, 3, -4, 5, -6, 7, -8, 9};
	//print_array(a); //传递的是,数组的首元素地址,&a[0]
	
	//a = NULL; //error
	
	int n = sizeof(a) / sizeof(a[0]);
	print_array2(a, n); //应该把数组元素个数传递过去

	return 0;
}

int main01()
{
	int a[] = {1, -2, 3, -4, 5, -6, 7, -8, 9};
	int i, j, tmp;
	int n = sizeof(a) / sizeof(*a);

	printf("before:\n");
	for(i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	//冒泡排序
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n-1-i; ++j)
		{
			if(a[j] > a[j+1]) //升序
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}

	printf("after:\n");
	for(i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
