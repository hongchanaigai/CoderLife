/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-06 16:06
 * Last modified  : 2020-08-06 16:06
 * Filename       : 07_思考题.c
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

void setStu(struct Student tmp)
{
	tmp.age = 22;
	strcpy(tmp.name, "mike");
	tmp.score = 60;
	printf("setStu:  %d, %s, %d\n", tmp.age, tmp.name, tmp.score);
}

void setStu01(struct Student *tmp)
{
	tmp->age = 22;
	strcpy(tmp->name, "mike");
	tmp->score = 60;
	printf("setStu01:  %d, %s, %d\n", tmp->age, tmp->name, tmp->score);
}

int main()
{
	struct Student s1 = {18, "huang", 59};

	setStu(s1); //值传递,通过函数修改成员内容
	printf("first: %d, %s, %d\n", s1.age, s1.name, s1.score);
	setStu01(&s1); //地址传递,通过函数修改成员内容
	printf("second: %d, %s, %d\n", s1.age, s1.name, s1.score);

	return 0;
}
