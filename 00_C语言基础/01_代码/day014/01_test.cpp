/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-17 17:49
 * Last modified  : 2020-08-17 19:47
 * Filename       : 01_test.cpp
 * Description    : 
 * *******************************************************/
#include <stdio.h>

struct Test
{
	//int a;

	void setA(int x)
	{
		a = x;
	}

	int getA()
	{
		return a;
	}

	int a;

	//函数的返回值是一个结构体类型的变量
	//函数的参数是一个结构体变量
	Test fun(Test obj)
	{
		printf("fun\n");

		return obj;
	}
};

int main()
{
	//Test结构体类型, C++中叫做类
	//obj结构体变量, C++叫做对象
	Test obj;

	//obj.a;
	
	//调用完毕setA()函数,a变量不会释放,只有obj生命周期结束了,变量才会释放
	obj.setA(10);
	int tmp = obj.getA();
	printf("tmp = %d\n", tmp);

	int n = ( obj.fun(obj) ).getA();
	printf("n = %d\n", n);

	return 0;
}
