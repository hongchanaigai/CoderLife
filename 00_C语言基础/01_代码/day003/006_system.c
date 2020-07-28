//002_system.c

#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("/******before system******/\n");
	//1、需要头文件  #include <stdlib.h>
	//2、system功能：调用外部程序
	int a = system("./005_external");
	printf("a = %d\n", a);
	printf("/******after system******/\n");

	return 0;
}
