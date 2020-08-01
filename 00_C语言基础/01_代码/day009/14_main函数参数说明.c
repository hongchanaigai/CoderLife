/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-01 19:32
 * Last modified  : 2020-08-01 19:32
 * Filename       : 14_main函数参数说明.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

//1. argv[]:它是数组,数组每个元素都是char *,每个元素都是字符地址
//2. argc:argv[]元素个数
//3. main()函数的参数,需要用户传递
int main(int argc, char *argv[])
{
	int i;
	for(i = 0; i < argc; ++i)
	{
		printf("test = %s\n", argv[i]);
	}

	return 0;
}
