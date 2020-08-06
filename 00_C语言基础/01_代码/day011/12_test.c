/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-06 17:23
 * Last modified  : 2020-08-06 17:23
 * Filename       : 12_test.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //strcpy()

struct Test
{
	char *str;
};

int main()
{
	struct Test obj;
	//strcpy(obj.str, "huang"); //段错误
	//给str指向的内存拷贝内存
	printf("str = %s\n", obj.str);

	return 0;
}
