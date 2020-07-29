/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 15:44
 * Last modified  : 2020-07-20 15:56
 * Filename       : 02_homework03.c
 * Description    : 输出100以内能被7整除的数,分别用for循环和while循环完成
 * *******************************************************/

#include <stdio.h>

int main()
{
	int i;

	for(i = 1; i < 100; ++i)
	{
		if(i % 7 == 0)
		{
			printf("%d\n", i);
		}
	}

	printf("///////////////////////////////////\n");

	i = 1;
	while(i <= 100)
	{
		if(i % 7 == 0)
		{
			printf("%d\n", i);
		}
		++i;
	}

	return 0;
}
