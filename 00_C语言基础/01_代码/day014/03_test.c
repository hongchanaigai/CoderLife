/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-17 19:48
 * Last modified  : 2020-08-17 19:59
 * Filename       : 03_test.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

struct Test
{
	int a;
	//类中声明,类外定义函数
	void setA();

	int getA();

	//静态函数
	static void func()
	{
		printf("func\n");
	}
};

//加上作用域,告诉编译器,setA()属于struct Test
void Test::setA()
{
	a = 10;
}

int Test::getA()
{
	return a;
}

int main()
{
	Test obj;
	obj.setA();
	int tmp = obj.getA();
	printf("tmp = %d\n", tmp);

	//静态函数,可以通过类型名调用,无需先创建对象
	//静态函数也可以通过对象调用
	Test::func();
	obj.func();
	
	//非静态函数,必须通过对象(结构体变量)调用
	
	return 0;
}
