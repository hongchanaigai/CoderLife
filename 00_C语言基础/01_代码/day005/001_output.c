//001_output.c
#include <stdio.h>

int main(int argc, char *argv[]){
	printf("hello, %s\n", "this is a string.");

	int a = 10;
	printf("&a = %p\n", &a);

	//%%在屏幕输出一个%,后面的d也会输出
	printf("%%\n");
	printf("%%d\n");

	a = 123;
	printf("a1 = '%d'\n", a);
	//%5d,以5个字符输出,没有字符以空字符填充,默认是右对齐
	printf("a2 = '%5d'\n", a);
	//%05d,以5个字符输出,没有字符以0字符填充,默认是右对齐
	printf("a3 = '%05d'\n", a);
	//%5d,以5个字符输出,没有字符以空字符填充,-代表是左对齐
	printf("a4 = '%-5d'\n", a);
	//0和-不能同时使用
	
	double b = 3.14;
	//默认小数点后有6位,不够补0
	printf("b1 = %lf\n", b);
	//8.3,8代表总共有8个字符,3代表小数点后面有3位
	printf("b2 = %8.3lf\n", b);

	char ch = 'a';
	putchar(ch);	//把ch的内容输出到屏幕
	//printf("\n");
	putchar('\n');

	return 0;
}
