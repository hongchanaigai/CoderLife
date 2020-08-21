#include <stdio.h>
#include <stdlib.h> //system()

int* getA()
{
	static int a = 10;
	return &a;
}

int main(void)
{
	int* p = getA();

	printf("\n");
	system("pause");
	return 0;
}