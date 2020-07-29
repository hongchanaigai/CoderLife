/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 22:05
 * Last modified  : 2020-07-20 22:05
 * Filename       : 23_随机数的产生.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//先设置种子,种子设置一次即可
	//如果srand()参数一样,随机数就一样
	//srand(100);
	
	//time(NULL)功能获取系统当前时间,由于时间会变,srand()也会改变
	srand((unsigned int)time(NULL));

	int i, num;
	for(i = 0; i < 10; ++i)
	{
		num = rand();	//rand()产生随机数
		printf("num = %d\n", num);
	}

	return 0;
}
