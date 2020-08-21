#include <stdio.h>
#include <stdlib.h> //system()

int main(void)
{
	int a;		//告诉编译器,分配4字节
	int b[10];	//告诉编译器,分配4 * 10字节

	/*
	类型的本质:固定内存块大小别名
	可以通过sizeof()测试
	*/
	printf("sizeof(a) = %d, sizeof(b) = %d\n", sizeof(a), sizeof(b));
	
	//打印地址
	/*
	b,&b的数据类型不一致
	1. b, 数组首元素地址,一个元素4字节, +1代表, +4字节
	2. &b, 整个数组的首地址,一个数组4*10 = 40字节, +1代表, +40字节
	*/
	printf("b = %p, &b = %p\n", b, &b);
	printf("b+1 = %p, &b+1 = %p\n", b+1, &b+1);

	//指针类型长度,32位程序,长度为4字节,64位程序,长度为8字节
	char*** p1 = NULL;
	int* p2 = NULL;
	printf("p1 = %d, p2 = %d\n", sizeof(p1), sizeof(p2));

	//printf("\n");
	//system("pause");
	return 0;
}