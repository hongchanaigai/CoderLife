/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-26 16:56
 * Last modified  : 2020-07-26 16:56
 * Filename       : 08_sprintf.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a = 10;
	char ch = 'd';
	char buf[] = "hello";

	//格式化一个字符串,把这个字符串输出到屏幕
	printf("a = %d, ch = %c, buf = %s\n", a, ch, buf);

	char dst[100];
	//格式化一个字符串,把这个字符串输出到(保存在)指定的数组
	sprintf(dst, "a = %d, ch = %c, buf = %s\n", a, ch, buf);
	printf("@@%s@@", dst);

	return 0;
}
