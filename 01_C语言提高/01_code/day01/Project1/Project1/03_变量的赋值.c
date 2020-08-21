#include <stdio.h>

int main(void)
{
	//变量本质: 一段连续内存空间别名
	//变量相当于门牌号,内存相当于房间
	int a;

	//直接赋值
	a = 10;

	printf("a = %d\n", a);

	//间接赋值
	printf("&a = %p\n", &a);
	int* p;
	p = &a;
	printf("p = %p\n", p);

	*p = 22;
	printf("*p = %d, a = %d\n", *p, a);

	return 0;
}