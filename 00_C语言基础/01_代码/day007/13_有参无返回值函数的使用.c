/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-26 19:28
 * Last modified  : 2020-07-26 19:28
 * Filename       : 13_有参无返回值函数的使用.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

//有参无返回值函数的定义
//1. 定义函数的参数叫做形参,形参格式必须为:类型+变量,不能赋值
//void func(int a = 10) //error
//2. 函数没有调用,形参变量不会分配空间,函数调用完毕,形参变量自动释放
void func(int a)
{
	printf("a = %d\n", a);
}

//3. 如果形参有多个,用逗号","分开
void func1(int a, char ch, char buf[100])
{
	printf("a = %d, ch = %c, buf = %s\n", a, ch, buf);
}


int main()
{
	int a = 10;

	//有参无返回值函数的调用
	//1. 如果函数定义是有参数,调用时必须传参
	//func(); //error
	//2. 有参函数调用形式:函数名字(匹配类型参数)
	//3. 匹配类型参数可以是变量\常量\表达式
	//4. 给函数调用时传的参数,叫实参
	//5. 只能把实参的值传递给形参,不能反过来,单向传递

	func(10); //实参是常量
	
	int i = 11;
	func(i); //实参是变量

	func(1 > 2); //实参是表达式


	//6. 函数的形参有多个,传参也用逗号","分开
	func1(10, 'a', "hello");

	return 0;
}
