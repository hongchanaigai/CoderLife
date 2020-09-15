#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(), sprintf()
#include <stdlib.h>	//system(), malloc(), free()
#include <string.h>	//strcpy()

typedef struct Teacher
{
	char* name;
	int age;
}Teacher;

Teacher* getMemory(int n)
{
	Teacher* q = (Teacher*)malloc(3 * sizeof(Teacher));
	if (q != NULL)
	{
		for (int i = 0; i < n; ++i)
		{
			q[i].name = (char*)malloc(20);
			if (q[i].name != NULL)
			{
				sprintf(q[i].name, "name_q%d", i + 1);
			}
		}
	}

	return q;
}

void showTeacher(Teacher* q, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("q[%d].name = %s\n", i, q[i].name);
	}
}

void freeTeacher(Teacher* q, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (q[i].name != NULL)
		{
			free(q[i].name);
			q[i].name = NULL;
		}
	}

	if (q != NULL)
	{
		free(q);
		q = NULL;
	}
}

int main(void)
{
#if 0
	char* pname = NULL;

	pname = (char*)malloc(20);
	if(pname != NULL)
		strcpy(pname, "name_pname");

	printf("pname = %s\n\n", pname);

	if (pname != NULL)
	{
		free(pname);
		pname = NULL;
	}
#endif // 0

#if 0
	//1
	Teacher t;

	t.name = (char*)malloc(20);
	if (t.name != NULL)
		strcpy(t.name, "name_t");

	printf("t.name = %s\n\n", t.name);

	if (t.name != NULL)
	{
		free(t.name);
		t.name = NULL;
	}

	//2
	Teacher* p = NULL;

	p = (Teacher*)malloc(sizeof(Teacher));
	if (p != NULL)
	{
		p->name = (char*)malloc(20);
		if (p->name != NULL)
		{
			strcpy(p->name, "name_p");
			printf("p->name = %s\n\n", p->name);
		}

		if (p->name != NULL)
		{
			free(p->name);
			p->name = NULL;
		}
	}

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
#endif	//0

#if 0
	//3
	Teacher* q = NULL;
	//Teacher q[3];

	q = (Teacher*)malloc(3 * sizeof(Teacher));
	if (q != NULL)
	{
		for (int i = 0; i < 3; ++i)
		{
			q[i].name = (char*)malloc(20);
			if (q[i].name != NULL)
			{
				sprintf(q[i].name, "name_q%d", i + 1);
			}
		}

		/*for (int i = 0; i < 3; ++i)
		{
			printf("q[%d].name = %s\n", i, q[i].name);
		}*/
		showTeacher(q, 3);

		/*for (int i = 0; i < 3; ++i)
		{
			if (q[i].name != NULL)
			{
				free(q[i].name);
				q[i].name = NULL;
			}
		}*/
		freeTeacher(q, 3);
	}

	if (q != NULL)
	{
		free(q);
		q = NULL;
	}
#endif	//0

	//3
	Teacher* q = NULL;
	//Teacher q[3];
	q = getMemory(3);

	showTeacher(q, 3);

	freeTeacher(q, 3);
	q = NULL;

	printf("\n");
	system("pause");
	return 0;
}