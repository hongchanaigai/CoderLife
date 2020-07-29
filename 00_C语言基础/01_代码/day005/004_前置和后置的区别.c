/**********************************************************
 * Author         : huang
 * Creat modified : 2020-06-26 15:49
 * Last modified  : 2020-06-26 15:56
 * Filename       : 004_前置和后置的区别.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[]){
	int a = 1;
	int b = 0;

	//后置++,先用后加
	//1)先把a的值赋值给b
	//2)a再自加1
	b = a++;
	printf("a1 = %d, b1 = %d\n", a, b);

	a = 1;
	b = 0;
	//前置++,先加后用
	b = ++a;
	printf("a2 = %d, b2 = %d\n", a, b);

	a = 1;
	b = 0;
	a++;	//先执行完此语句,再往下执行
	b = a;	//执行到此语句,a的值已经是2
	printf("a3 = %d, b3 = %d\n", a, b);

	return 0;
}
