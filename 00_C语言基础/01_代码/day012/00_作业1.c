/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 15:10
 * Last modified  : 2020-08-07 15:10
 * Filename       : 00_作业1.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

typedef struct student
{
	char *name; //姓名
	unsigned int age; //年龄
	int score; //成绩
}student;

void print_stu(student *stu, int n)
{
	int i;
	printf("name\tage\tscore\n");
	for(i = 0; i < n; ++i)
	{
		printf("%s\t%d\t%d\n", stu[i].name, stu[i].age, stu[i].score);
	}
}

void sort_stu(student *stu, int n)
{
	int i;
	int j;
	student tmp; //临时结构体变量

	//冒泡排序,按照年龄排序,如果年龄相同,按照成绩排序
	for(i = 0; i < n-1; ++i)
	{
		for(j = 0; j < n-1-i; ++j)
		{
			if(stu[j].age > stu[j+1].age) //升序
			{
				tmp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = tmp;
			}
			else if(stu[j].age == stu[j+1].age) //如果年龄相同,按照成绩排序
			{
				if(stu[j].score > stu[j+1].score) //升序
				{
					tmp = stu[j];
					stu[j] = stu[j+1];
					stu[j+1] = tmp;
				}
			}
		}
	}
}

int main()
{
	student stu[5] = 
	{
		{"aaaa", 18, 90},
		{"bbbb", 18, 80},
		{"cccc", 38, 37},
		{"dddd", 22, 80},
		{"eeee", 44, 23}
	};

	int n = sizeof(stu) / sizeof(stu[0]);

	printf("before: \n");
	print_stu(stu, n);

	//排序
	sort_stu(stu, n);

	printf("\nafter: \n");
	print_stu(stu, n);

	return 0;
}
