/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-29 17:42
 * Last modified  : 2020-07-29 17:42
 * Filename       : 20_指向数组首元素的指针.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *p = NULL;
	//p指针变量指向首元素
	p = &a[0];
	p = a;

	int i;
	for(i = 0; i < 10; ++i)
	{
		//printf("%d, ", a[i]);
		printf("%d, ", *(a+i));

		//printf("%d, ", *(p+i));
		//p[i]等价于*(p+i),操作都是指针所指向的内存
		//printf("%d, ", p[i]);
	}
	printf("\n");

	return 0;
}
