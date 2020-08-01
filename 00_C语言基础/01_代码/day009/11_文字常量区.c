/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-01 17:37
 * Last modified  : 2020-08-01 17:37
 * Filename       : 11_文字常量区.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

void func()
{
	*tmp = 'a';
}

int main()
{
	char *p = NULL; //p是变量
	"hello huang"; //字符串常量,首元素地址

	p = "hello huang"; //p指向字符串
	//*p = 'a'; //error,指向文字常量区,文字常量区的内容只读
	p = NULL; //ok
	p = "hello"; //ok

	char *p2 = "abc";
	//func(p2); //p2的值,是"abc"首元素的地址,error

	return 0;
}
