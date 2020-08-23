#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>	//strcpy()

int main(void)
{
	char* p = NULL;
	printf("p1 = %p\n", p);
	//改变指针变量p的值
	char buf[] = "abcde";
	p = buf;
	printf("p2 = %p\n", p);

	//指针变量,和指针指向的内存,是两个概念
	p = p + 1;	//改变了指针变量的值,改变了指针的指向
	printf("p3 = %p\n", p);
	printf("buf1 = %s\n", buf);

	printf("*p = %c\n", *p);

	//改变指针指向的内存,并不会影响指针变量p的值
	printf("\n");
	buf[1] = '1';
	printf("p4 = %p\n", p);
	printf("buf2 = %s\n", buf);

	*p = 'm';
	printf("p5 = %p\n", p);
	printf("buf3 = %s\n", buf);

	//写内存时,一定要确保内存可写
	char* str1 = "shodfjepvkeprfjvoahcodjc";	//文字常量区,内存不允许修改
	//str1[2] = '2';	//error,文字常量区内容不可以修改

	char str2[] = "shodfjepvkeprfjvoahcodjc";	//栈区,内存允许修改
	str2[2] = '2';	//ok,栈区内容可以修改

	char* q1 = NULL;
	//strcpy()函数的功能: 给q1指向的内存区域拷贝内容
	//q1 = str2;	//确定指向后就不会发生错误
	//strcpy(q1, "1111");	//error

	printf("\n");
	system("pause");
	return 0;
}