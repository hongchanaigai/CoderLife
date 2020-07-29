/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-19 21:02
 * Last modified  : 2020-07-19 21:04
 * Filename       : 021_goto.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	goto huang;

	printf("11111\n");
	printf("22222\n");

huang:
	printf("33333\n");

	return 0;
}
