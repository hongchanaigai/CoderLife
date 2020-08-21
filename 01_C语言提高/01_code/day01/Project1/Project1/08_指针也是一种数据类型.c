#include <stdio.h>
#include <stdlib.h> //system()

int main(void)
{
	int* p = NULL;
	char******* q = NULL;
	printf("sizeof(p) = %d, sizeof(q) = %d\n", sizeof(p), sizeof(q));

	int a = 100;
	int* pa = NULL;
	//指针指向谁,就把谁的地址赋值给指针
	pa = &a;
	//*钥匙,通过*可以找到指针指向的内存区域,操作的还是内存
	*pa = 22;

	//*放在=左边,给内存赋值,写内存
	//*放在=右边,取内存的值,读内存
	int b = *pa;
	printf("b = %d\n", b);

	printf("\n");
	system("pause");
	return 0;
}