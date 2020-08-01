/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-30 20:06
 * Last modified  : 2020-07-30 20:13
 * Filename       : 05_字符指针.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main()
{
	char str[] = "hello huang";

	//1. %s,从首元素开始打印,知道结束符为止
	//2. %s,操作的是指针所指向的内容
	//printf("str = %s\n", str);
	
	//3, str是首元素地址,如果想打印str本身的值,%p,%x,%d,%o
	printf("str = %p\n", str);

	//4. *str代表第0个元素,它是char类型
	//printf("*str = %s\n", *str); //error,段错误
	printf("*str = %c\n", *str);
	
	int i = 0;
	while(str[i] != '\0') //while(*(str+i) != '\0')
	{
		printf("%c", str[i]); //*(str+i)和str[i]等价
		++i;
	}
	printf("\n");

	return 0;
}
