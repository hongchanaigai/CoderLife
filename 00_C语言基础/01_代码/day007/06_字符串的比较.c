/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-25 19:28
 * Last modified  : 2020-07-25 19:28
 * Filename       : 06_字符串的比较.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>
#include <string.h> //strcmp(), strncmp()

int main()
{
	char s1[] = "abc";
	//char s2[] = "abcd";
	char s2[] = "Abcd";
	//int flag = strcmp(s1, s2);
	int flag = strncmp(s1, s2, 3); //指定比较前3个字符
	if(flag > 0)
	{
		printf("[%s] > [%s]\n", s1, s2);
	}
	else if(flag < 0)
	{
		printf("[%s] < [%s]\n", s1, s2);
	}
	else
	{
		printf("[%s] == [%s]\n", s1, s2);
	}
}
