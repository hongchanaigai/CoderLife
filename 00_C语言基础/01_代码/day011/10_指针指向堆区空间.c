/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-06 17:01
 * Last modified  : 2020-08-06 17:16
 * Filename       : 10_指针指向堆区空间.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h> //malloc(),free()

struct Student
{
	int age;
	int score;
};

int main()
{
	//定义一个结构体类型的指针
	struct Student *p;

	//指针指向堆区空间
	p = (struct Student *)malloc(sizeof(struct Student));
	if(p == NULL) //分配失败
	{
		printf("malloc error!!!\n");
		return -1;
	}

	p->age = 18;
	p->score = 59;
	printf("%d, %d\n", p->age, p->score); //打印s

	if(p != NULL)
	{
		free(p);
		p = NULL;
	}

	return 0;
}
