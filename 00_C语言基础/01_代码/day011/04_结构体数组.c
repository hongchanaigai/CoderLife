/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-05 18:25
 * Last modified  : 2020-08-05 18:25
 * Filename       : 04_结构体数组.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //strcpy()

struct Student
{
	int age;
	char name[50];
	int score;
};

int main()
{
	struct Student a[5] = 
	{
		{18, "huang1", 55},
		{19, "huang2", 66},
		{20, "huang3", 77},
		{21, "huang4", 88},
		{22, "huang5", 99}
	};

	//求平均分
	int sum = 0;
	int i;
	int n = sizeof(a) / sizeof(a[0]);

	for(i = 0; i < n; ++i)
	{
		sum += a[i].score;
	}

	printf("ave = %f\n", sum*1.0 / n);

	return 0;
}

int main01()
{
	struct Student s;

	struct Student a[5];
	//操作元素
	a[0].age = 18;
	strcpy(a[0].name, "huang0");
	a[0].score = 59;

	//操作某个元素地址
	(a+1)->age = 19;
	strcpy((a+1)->name, "huang1");
	(a+1)->score = 60;

	//操作元素
	(*(a+2)).age = 20;
	strcpy((*(a+2)).name, "huang2");
	(*(a+2)).score = 61;

	struct Student *p = a;
	p = &a[0];

	p[3].age = 21;
	strcpy(p[3].name, "huang3");
	p[3].score = 62;

	(p+4)->age = 22;
	strcpy((p+4)->name, "huang4");
	(p+4)->score = 63;

	int i;
	int n = sizeof(a) / sizeof(a[0]);
	for(i = 0; i < n; ++i)
	{
		printf("%d, %s, %d\n", a[i].age, a[i].name, a[i].score);
	}

	return 0;
}
