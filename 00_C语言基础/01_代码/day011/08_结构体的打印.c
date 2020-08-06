/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-06 16:38
 * Last modified  : 2020-08-06 16:38
 * Filename       : 08_结构体的打印.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

struct Student
{
	int age;
	char name[50];
	int score;
}; //有分号

void func(struct Student tmp)
{
	tmp.age  = 22;
	printf("%d, %s, %d\n", tmp.age, tmp.name, tmp.score); //打印tmp
}

void func2(struct Student const *tmp)
{
	printf("%d, %s, %d\n", tmp->age, tmp->name, tmp->score); //打印s1
}

int main()
{
	struct Student s1 = {18, "huang", 59};

	func(s1);

	func2(&s1);

	return 0;
}
