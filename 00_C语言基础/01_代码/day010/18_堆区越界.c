/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-03 19:08
 * Last modified  : 2020-08-03 19:08
 * Filename       : 18_堆区越界.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h> //malloc(),free()
#include <string.h> //strcpy()

int main()
{
	char *p = NULL;

	p = (char *)malloc(0); //error,实际上并未分配空间,但是结果正确

	if(NULL == p)
	{
		printf("malloc fail!!!");
		return -1;
	}

	strcpy(p , "huang");
	printf("%s\n", p);

	if(NULL != p)
	{
		free(p);
		p = NULL;
	}

	return 0;
}
