/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-25 19:21
 * Last modified  : 2020-07-25 19:21
 * Filename       : 05_字符数组越界.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>
#include <string.h> //strcpy()

int main()
{
	char src[100] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char dst[10];
	strcpy(dst, src);
	printf("dst = %s\n", dst);

	return 0;
}
