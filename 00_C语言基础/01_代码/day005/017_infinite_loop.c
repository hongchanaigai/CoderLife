/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-19 19:50
 * Last modified  : 2020-07-19 19:53
 * Filename       : 017_infinite_loop.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	for(; ;)
	{
		printf("it is infinite loop.\n");
	}

	return 0;
}
