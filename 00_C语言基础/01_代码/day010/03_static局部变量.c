/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-02 19:22
 * Last modified  : 2020-08-02 19:22
 * Filename       : 03_static局部变量.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

void func()
{
	int i = 0;
	++i;
	printf("i = %d\n", i);
}

void static_func()
{
	//1. 在{}内部定义的变量就是局部变量 
	//2. static局部变量,实在编译阶段就已经分配空间,函数没有调用前,它就就已经存在
	//3. 当离开{},static局部变量不会释放,只有程序结束,static变量才会释放
	//4. 局部变量的作用域在当前的{},离开此{},无法使用此变量
	//5. 不同的{}中,变量名字可以一样,可以把{}类比房子,不同房子可以有同名的人
	//6. 如果static局部变量不初始化,它的值默认为0
	//7. static局部变量初始化语句,只会执行一次,但是可以赋值多次
	//8. static变量只能用常量初始化(注意)
	static int i = 0;
	++i;
	printf("static i = %d\n", i);

	int a = 10;
	static int j = a; //error,使用变量a给static变量j初始化
}

int main()
{
	func(); //i = 1
	func(); //i = 1
	func(); //i = 1

	static_func(); //static i = 1;
	static_func(); //static i = 2;
	static_func(); //static i = 3;

	return 0;
}
