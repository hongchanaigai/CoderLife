/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-26 19:15
 * Last modified  : 2020-07-26 19:22
 * Filename       : 12_无参无返回值函数的使用.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

//无参无返回值函数的使用
//1. 没有返回值,用void关键字修饰
//2. 没有参数,也可以用void,或者空
//3. 第一个void代表返回值,func代表函数名字,()内部代表参数,空代表无参,{}就是函数体
//4. 同一个文件不能出现同名函数
//5. 不同的函数,内部的变量是没有关系的
void func(void) //等价于 void func()
{
	printf("无参无返回值函数的定义\n");

	//函数内部,包括()内部的变量,只有在调用时分配空间,调用完毕自动释放
	int a = 10;
	int b = 20;
	printf("a + b = %d\n", a+b);
}

int main()
{
	//1. 除了main(),其他函数只有调用了才起作用
	//2. 函数的调用不可能出现void关键字
	//void func(); //error
	//3. 无参无返回值函数的调用格式: 函数名字()
	//func(void); //error
	func();

	//main()函数的a,b和func()函数的a,b没有关系
	int a = 10;
	int b = 20;

	return 0;
}
