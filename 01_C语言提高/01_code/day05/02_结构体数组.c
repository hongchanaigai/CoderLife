#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(), sprintf()
#include <stdlib.h>	//system()
#include <string.h>	

typedef struct Teacher
{
	char name[20];
	int age;
}Teacher;

int main(void)
{
	Teacher a[3] = {
		{"Teacher_a1", 11},
		{"Teacher_a2", 22},
		{"Teacher_a3", 33}
	};
	for (int i = 0; i < 3; ++i)
	{
		printf("%s, %d\n", a[i].name, a[i].age);
	}
	printf("\n");

	//¾²Ì¬
	Teacher b[3] = { "Teacher_b1", 11, "Teacher_b2", 22, "Teacher_b3", 33 };
	for (int i = 0; i < 3; ++i)
	{
		printf("%s, %d\n", b[i].name, b[i].age);
	}
	printf("\n");

	//¶¯Ì¬
	Teacher* p = NULL;
	p = (Teacher*)malloc(3 * sizeof(Teacher));
	if (p == NULL)
	{
		printf("main: malloc error\n");
		return -1;
	}

	for (int i = 0; i < 3; ++i)
	{
		char tmp_buf[20];
		sprintf(p[i].name, "Teacher_p%d", i+1);
		p[i].age = (i + 1) * 10 + (i + 1);
	}

	for (int i = 0; i < 3; ++i)
	{
		printf("%s, %d\n", p[i].name, p[i].age);
	}

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	printf("\n");
	system("pause");
	return 0;
}