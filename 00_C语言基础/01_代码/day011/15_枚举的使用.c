/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-06 18:54
 * Last modified  : 2020-08-06 18:54
 * Filename       : 15_枚举的使用.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

//#define pink 0
//#define red 1
//#define green 2
//#define white 3
//#define blue 4
//#define yellow 5

//enum是关键字
//里面的成员是一个标示符,枚举常量
//第一个成员如果没有赋值默认为0,下一个成员比上一个成员多1
//枚举类型
//成员: 枚举成员,枚举常量
enum Color
{
	pink, red, green, white, blue, yellow
};

int main()
{
	int flag = 1;
	if(flag == red)
	{
		printf("red\n");
	}

	//枚举变量flag2
	enum Color flag2;
	
	//1. 可以使用枚举成员给flag2赋值
	flag2 = pink; //等价于flag2 = 0

	//2. 也可以使用常量给flag2赋值,不推荐
	flag2 = 0;

	return 0;
}

int main01()
{
	int flag;

	if(flag == red)
	{
	}
	else if(flag == blue)
	{
	}

	return 0;
}
