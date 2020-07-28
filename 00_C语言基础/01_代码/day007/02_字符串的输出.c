/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-25 18:27
 * Last modified  : 2020-07-25 18:27
 * Filename       : 02_字符串的输出.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main00()
{
	char buf[] = "hello";
	//printf("%s", buf); //没有加换行符
	puts(buf); //把buf内容输出到屏幕,自动在屏幕加换行,字符串本身无变化
	//printf("%s", buf);
	
	return 0;
}

int main()
{
	char buf[] = "hello";

	//往stdout(代表屏幕,标准输出),输出buf的内容
	fputs(buf, stdout);

	return 0;
}
