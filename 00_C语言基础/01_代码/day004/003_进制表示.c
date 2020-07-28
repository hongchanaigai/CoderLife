//003_进制表示.c

#include <stdio.h>

int main(int argc, char *argv[]){
	int a;
	a = 123;	//以10进制方式赋值
	//%d，以10进制方式打印
	printf("[10] a = %d\n", a);
	//%o，以8进制方式打印
	printf("[8] a = %o\n", a);
	//%x，%X，以16进制方式打印
	printf("[16] a = %x\n", a);

	a = 0123;	//以8进制方式赋值
	a = 0x123;	//以16进制方式赋值

	return 0;
}
