/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 15:58
 * Last modified  : 2020-07-20 16:09
 * Filename       : 03_homework04.c
 * Description    : 输出0-1000以内的水仙花数
 * *******************************************************/

#include <stdio.h>

int main()
{
	int i;
	int g, s, b;

	for(i = 0; i <= 1000; ++i)
	{
		g = i % 10;
		s = (i % 100) / 10;
		b = i / 100;

		if(i == g*g*g + s*s*s + b*b*b)
		{
			printf("%d\n", i);
		}
	}	

	return 0;
}
