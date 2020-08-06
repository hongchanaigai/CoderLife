/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-06 17:01
 * Last modified  : 2020-08-06 17:01
 * Filename       : 09_指针指向栈区空间.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

struct Student
{
	int age;
	int score;
};

int main()
{
	//定义一个结构体类型的指针
	struct Student *p;

	//在栈区定义一个结构体变量
	struct Student s;
	p = &s;

	p->age = 18;
	p->score = 59;
	printf("%d, %d\n", p->age, p->score); //打印s

	return 0;
}
