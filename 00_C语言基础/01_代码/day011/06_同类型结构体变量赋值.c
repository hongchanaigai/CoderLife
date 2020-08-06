/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-06 15:55
 * Last modified  : 2020-08-06 15:55
 * Filename       : 06_同类型结构体变量赋值.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //strcpy()

struct Student
{
	int age;
	char name[50];
	int score;
}; //有分号

int main()
{
	int a = 10;
	int b;
	//1. 把a的值给了b
	//2. a和b有关系吗?没有关系
	b = a;

	//1. 相同类型的2个结构体变量可以互相赋值
	//2. 尽管2个结构体变量内容一样,但是两个变量是没有关系的独立内存
	struct Student s1 = {18, "huang", 59};
	struct Student s2;
	s2 = s1;
	printf("%d, %s, %d\n", s2.age, s2.name, s2.score);

	return 0;
}
