/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-05 18:57
 * Last modified  : 2020-08-05 18:57
 * Filename       : 05_结构体嵌套.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //strcpy()

struct Info
{
	int age;
	char name[50];
};

struct Student
{
	struct Info info;
	int score;
};

int main()
{
	struct Student s;
	s.info.age = 18;
	strcpy(s.info.name, "huang");
	s.score = 60;

	struct Student *p = &s;
	p->info.age = 18;
	strcpy(p->info.name, "huang");
	p->score = 60;

	struct Student tmp = {18, "huang", 60};

	printf("%d, %s, %d\n", s.info.age, s.info.name, s.score);

	return 0;
}
