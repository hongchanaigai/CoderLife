/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-25 19:36
 * Last modified  : 2020-07-25 19:36
 * Filename       : 07_字符串追加.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>
#include <string.h> //strcat(), strncat()

int main()
{
	char src[] = " hello mike";
	char dst[100] = "abc";
	//把src的内容追加到dst的后面
	//strcat(dst, src); //dst = "abc hello mike";
	//strcpy(dst, src);
	strncat(dst, src, strlen(" hello")); //指定长度追加,dst = "abc hello"
	printf("dst = %s\n", dst);

	return 0;
}
