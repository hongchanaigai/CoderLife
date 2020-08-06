/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-05 18:20
 * Last modified  : 2020-08-05 18:20
 * Filename       : 03_结构体其他用法.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

struct Student
{
	int age;
	char name[50];
	int score;
}s1 = {18, "huang",59}, s2;

struct
{
	int age;
	char name[50];
	int score;
}s3, s4;

int main()
{
	printf("%d, %s, %d\n", s1.age, s1.name, s1.score);

	return 0;
}
