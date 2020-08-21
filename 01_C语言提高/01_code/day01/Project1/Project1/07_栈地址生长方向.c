#include <stdio.h>
#include <stdlib.h> //system()

int main(void)
{
	int a;
	int b;
	printf("&a = %p, &b = %p\n", &a, &b);

	int buf[10];
	printf("buf: %p, buf+1: %p\n", buf, buf + 1);

	printf("\n");
	system("pause");
	return 0;
}