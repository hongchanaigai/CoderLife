/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-01 16:40
 * Last modified  : 2020-08-01 16:40
 * Filename       : 10_字符串常量.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //strcpy()

int main()
{
	//1. 字符串常量就是此字符串的首元素
	printf("s1 = %p\n", "hello huang");

	char *p1 = "hello huang";
	printf("p1 = %p\n", p1);

	char *p2 = "hello huang";
	printf("p2 = %p\n", p2);

	//2. 字符串常量,文字常量区的字符串,只读,不能修改
	printf("*p1 = %c\n", *p1); //读,ok

	//3. p1指向字符串常量,字符串常量只读,不能修改
	*p1 = 'a'; //修改,error

	char *p3 = "hello";
	//4. p3指向文字常量区内存,不能改变
	//strcpy(p3, "abc"); //error,段错误

	return 0;
}

void func()
{
	printf("func s2 = %p\n", "hello huang");
}

int main01()
{
	//1. 每个字符都是一个地址,这个地址是指字符串的首元素地址
	//2. 字符串常量放在data区,文字常量区
	
	printf("s1 = %s\n", "hello huang");
	printf("s1 = %p\n", "hello huang");
	printf("s3 = %s\n", "hello huang" + 1);
	printf("s4 = %c\n", *("hello huang")); //取首元素

	//func();

	return 0;
}
