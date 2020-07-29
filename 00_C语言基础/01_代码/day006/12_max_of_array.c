/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 19:21
 * Last modified  : 2020-07-20 19:21
 * Filename       : 12_max_of_array.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a[] = {10, -1, 20, 3, 5, 9, 2, 1, 9, 8, 7, 6};
	int n = sizeof(a) / sizeof(a[0]);
	int max = a[0];

	int i = 0;
	for(i = 1; i < n; ++i)
	{
		if(a[i] > max)
		{
			max = a[i];
		}
	}

	printf("the max number of array is %d.\n", max);

	return 0;
}
