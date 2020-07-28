/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 15:10
 * Last modified  : 2020-07-20 15:30
 * Filename       : 00_homework01.c
 * Description    : 从屏幕上输入一个学生的成绩(0-100),对学生成绩进行评定
 * *******************************************************/

#include <stdio.h>

int main()
{
	int score;
	printf("please input a student score: ");
	scanf("%d", &score);

	if(0 <= score && score < 60)
	{
		printf("the grede is E.\n");
	}
	else if(60 <= score && score < 70)
	{
		printf("the grade is D.\n");
	}
	else if(70 <= score && score < 80)
	{
		printf("the grade is C.\n");
	}
	else if(80 <= score && score < 90)
	{
		printf("the grade is B.\n");
	}
	else if(90 <= score && score <= 100)
	{
		printf("the grade is A.\n");
	}
	else
	{
		printf("input error!!!\n");
	}

	return 0;
}
