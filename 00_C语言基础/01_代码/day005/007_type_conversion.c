/**********************************************************
 * Author         : huang
 * Creat modified : 2020-06-26 16:34
 * Last modified  : 2020-06-26 16:57
 * Filename       : 007_type_conversion.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[]){
	double a;
	int b = 10;

	//隐式转换,编译器内容自动转换
	//b自动转换为double,再给a赋值,在16行自动转换,其他地方,b还是int型
	a = b;
	printf("a = %lf\n", a);

	//强制类型转换:(类型)需要转换的变量名
	double c;
	//把1强制转换为double型后再运算
	c = (double)1/2;
	printf("c = %lf\n", c);

	//64位
	printf("sizeof(int) = %u\n", (unsigned int)sizeof(int));

	//关于浮点型打印说明
	int d = 11;
	//整型变量不要用%lf打印,除非强制类型转换
	printf("d = %lf\n", (double)d);

	double e = 3.14;
	//浮点型变量不要用%d打印,除非强制类型转换
	printf("e = %d\n", (int)e);

	//强制类型转换原则:数据类型小的往大的转换
	int f = 129;
	char g = 111;

	//小的往大的转换
	//f = (int)g;
	//printf("f = %d\n", f);

	//大的往小的转换
	g = (char)f;
	printf("g = %d\n", g);

	return 0;
}
