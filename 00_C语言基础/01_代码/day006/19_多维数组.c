/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 21:22
 * Last modified  : 2020-07-20 21:22
 * Filename       : 19_多维数组.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	//1. 定义1个一维数组b[3],有3个元素,每个元素int[3][4]
	//2. 输出使用3重for循环
	int b[3][3][4];

	int i, j, k;
	for(i = 0; i < 3; ++i)
	{
		for(j = 0; j < 3; ++j)
		{
			for(k = 0; k < 4; ++k)
				b[i][j][k] = i+j+k;
		}
	}

	return 0;
}
