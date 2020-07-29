/**********************************************************
 * Author         : huang
 * Creat modified : 2020-06-26 14:25
 * Last modified  : 2020-06-26 14:53
 * Filename       : 002_input.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[]){
	/*
	//整型的输入
	int a;
	printf("please enter a: ");
	scanf("%d", &a);
	printf("a = %d\n", a);

	int b;
	int c;
	printf("please enter b, c: ");
	scanf("%d %d",  &b, &c);
	printf("b = %d, c = %d\n", b, c);
	*/

	//字符的输入
	char ch1;
	printf("please enter a char ch1: ");
	//scanf("%c", &ch1);
	ch1 = getchar();	//读取键盘的字符,放在ch1变量
	printf("ch1 = '%c'\n", ch1);

	//吃掉上一步的\n,不做处理
	char ch2;
	//printf("please enter a char ch2: ");
	//scanf("%c", &ch2);
	ch2 = getchar();
	//printf("ch2 = '%c'\n", ch2);
	
	char ch3;
	printf("please enter a char ch3: ");
	//scanf("%c", &ch3);
	ch3 = getchar();
	printf("ch3 = %c\n", ch3);

	return 0;
}
