/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 20:30
 * Last modified  : 2020-08-07 20:30
 * Filename       : 10_通过fgets读取键盘的内容.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main()
{
	char buf[100];
	while(1)
	{
		fgets(buf, sizeof(buf), stdin);
		printf("@%s@", buf);
	}

	return 0;
}
