#include <stdio.h>

char* get_str1(void)
{
	char* p = "abcdef";	//文字常量区

	return p;
}

char* get_str2(void)
{
	char* q = "abcdef";	//文字常量区

	return q;
}

int main(void)
{
	char* p = NULL;
	char* q = NULL;

	//%s: 指针指向内存区域的内容
	//%d: 指针p本身的值
	p = get_str1();
	printf("p = %s, p = %p\n", p, p);
	
	q = get_str2();
	printf("q = %s, q = %p\n", q, q);

	return 0;
}