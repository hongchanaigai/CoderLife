#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(), sprintf()
#include <stdlib.h>	//system(), malloc(), free()
#include <string.h>

//一个导师,n个学生
typedef struct Teacher
{
	int age;
	char** stu;	//二维内存
}Teacher;

//n1: 老师个数
//n2: 每个老师所带学生的个数
int createTeacher(Teacher** tmp, int n1, int n2)
{
	if (tmp == NULL)
	{
		printf("createTeacher: input error: tmp == NULL\n");
		return -1;
	}

	Teacher* q = (Teacher*)malloc(n1 * sizeof(Teacher));
	//Teacher q[3]

	if (q != NULL)
	{
		//对每个q[i]进行操作
		for (int i = 0; i < n1; ++i)
		{
			q[i].age = (i + 1) * 10 + (i + 1);
			q[i].stu = (char**)malloc(n2 * sizeof(char*));
			//char* stu[3]

			if (q[i].stu != NULL)
			{
				//对每个q[i].stu[j]进行操作
				for (int j = 0; j < n2; ++j)
				{
					q[i].stu[j] = (char*)malloc(20);
					//char stu[j]

					if (q[i].stu[j] != NULL)
					{
						sprintf(q[i].stu[j], "q[%d].stu%d", i + 1, j + 1);
					}
				}
			}
		}
	}

	//间接赋值是指针存在最大意义
	*tmp = q;

	return 0;
}

//n1: 老师个数
//n2: 每个老师所带学生的个数
void showTeacher(Teacher* q, int n1, int n2)
{
	if (q == NULL)
	{
		printf("showTeacher: input error: q == NULL\n");
		return;
	}

	for (int i = 0; i < n1; ++i)
	{
		printf("q[%d].age = %d\n", i + 1, q[i].age);

		for (int j = 0; j < n2; ++j)
		{
			printf("q[%d].stu[%d] = %s\n", i + 1, j + 1, q[i].stu[j]);
		}
		printf("\n");
	}
}

//n1: 老师个数
//n2: 每个老师所带学生的个数
void sortTeacher(Teacher* q, int n1)
{
	if (q == NULL)
	{
		printf("sortTeacher: input error: tmp == NULL\n");
		return;
	}

	//选择法排序,根据老师的年龄降序
	for (int i = 0; i < n1 - 1; ++i)
	{
		for (int j = i + 1; j < n1; ++j)
		{
			if (q[i].age < q[j].age)
			{
				Teacher tmp_q = q[i];
				q[i] = q[j];
				q[j] = tmp_q;
			}
		}
	}
}

//n1: 老师个数
//n2: 每个老师所带学生的个数
void freeTeacher(Teacher** tmp, int n1, int n2)
{
	if (tmp == NULL)
	{
		printf("freeTeacher: input error: tmp == NULL\n");
		return;
	}

	Teacher* q = *tmp;

	//释放q[i].stu[j]
	for (int i = 0; i < n1; ++i)
	{
		for (int j = 0; j < n2; ++j)
		{
			if (q[i].stu[j] != NULL)
			{
				free(q[i].stu[j]);
				q[i].stu[j] = NULL;
			}
		}
	}

	//释放每个q[i]
	for (int i = 0; i < n1; ++i)
	{
		if (q[i].stu != NULL)
		{
			free(q[i].stu);
			q[i].stu = NULL;
		}
	}

	//释放q
	if (q != NULL)
	{
		free(q);
		q = NULL;
	}
}

int main(void)
{
#if 0
	char** name = NULL;
	//char* name[3]
	int n = 3;
	name = (char**)malloc(n * sizeof(char*));
	//char buf[20];
	if (name != NULL)
	{
		for (int i = 0; i < n; ++i)
		{
			name[i] = (char*)malloc(20);
			if (name[i] != NULL)
			{
				sprintf(name[i], "name%d", i + 1);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			printf("name[%d] = %s\n", i, name[i]);
		}

		for (int i = 0; i < n; ++i)
		{
			if (name[i] != NULL)
			{
				free(name[i]);
				name[i] = NULL;
			}
		}
	}

	if (name != NULL)
	{
		free(name);
		name = NULL;
	}
#endif	//0

#if 0
	//1
	Teacher t;
	//t.stu[3]
	int n = 3;
	t.stu = (char**)malloc(n * sizeof(char*));
	//char buf[20];
	if (t.stu != NULL)
	{
		for (int i = 0; i < n; ++i)
		{
			t.stu[i] = (char*)malloc(20);
			if (t.stu[i] != NULL)
			{
				sprintf(t.stu[i], "t.stu%d", i + 1);
}
		}

		for (int i = 0; i < n; ++i)
		{
			printf("t.stu[%d] = %s\n", i, t.stu[i]);
		}

		for (int i = 0; i < n; ++i)
		{
			if (t.stu[i] != NULL)
			{
				free(t.stu[i]);
				t.stu[i] = NULL;
			}
		}
	}

	if (t.stu != NULL)
	{
		free(t.stu);
		t.stu = NULL;
	}
#endif	//0

#if 0
	//2
	Teacher* p = NULL;
	//p->stu[3]
	int n = 3;
	p = (Teacher*)malloc(sizeof(Teacher));
	if (p != NULL)
	{
		p->stu = (char**)malloc(n * sizeof(char*));
		//char* p->stu[3]
		if (p->stu != NULL)
		{
			for (int i = 0; i < n; ++i)
			{
				p->stu[i] = (char*)malloc(20);
				if (p->stu[i] != NULL)
				{
					sprintf(p->stu[i], "p->stu%d", i + 1);
				}
			}

			for (int i = 0; i < n; ++i)
			{
				printf("p->stu[%d] = %s\n", i, p->stu[i]);
			}

			for (int i = 0; i < n; ++i)
			{
				if (p->stu[i] != NULL)
				{
					free(p->stu[i]);
					p->stu[i] = NULL;
				}
			}
		}

		if (p->stu != NULL)
		{
			free(p->stu);
			p->stu = NULL;
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
	//Teacher q[3]
	//q[i].stu[3]
	int n = 3;

	q = (Teacher*)malloc(n * sizeof(Teacher));
	//Teacher q[3]
	if (q != NULL)
	{
		//对每个q[i]进行操作
		for (int i = 0; i < n; ++i)
		{
			q[i].stu = (char**)malloc(n * sizeof(char*));
			//char* stu[3]
			if (q[i].stu != NULL)
			{
				//对每个q[i].stu[j]进行操作
				for (int j = 0; j < n; ++j)
				{
					q[i].stu[j] = (char*)malloc(20);
					//char stu[j]
					if (q[i].stu[j] != NULL)
					{
						sprintf(q[i].stu[j], "q[%d].stu%d", i, j + 1);
					}
				}

				//输出结果
				for (int j = 0; j < n; ++j)
				{
					printf("q[%d].stu[%d] = %s\n", i, j, q[i].stu[j]);
				}
				printf("\n");

				//释放q[i].stu[j]
				for (int j = 0; j < n; ++j)
				{
					if (q[i].stu[j] != NULL)
					{
						free(q[i].stu[j]);
						q[i].stu[j] = NULL;
					}
				}
			}
		}

		//释放每个q[i]
		for (int i = 0; i < n; ++i)
		{
			if (q[i].stu != NULL)
			{
				free(q[i].stu);
				q[i].stu = NULL;
			}
		}
	}

	//释放q
	if (q != NULL)
	{
		free(q);
		q = NULL;
	}
#endif	//0

	//3
	Teacher* q = NULL;

	//创建Teacher q[3]
	int ret = 0;
	ret = createTeacher(&q, 3, 3);
	if (ret != 0)
	{
		printf("main: createTeacher error: %d\n", ret);
		return ret;
	}
	
	//排序前,输出结果
	printf("before sort:\n");
	showTeacher(q, 3, 3);

	//排序
	sortTeacher(q, 3);

	//排序后,输出结果
	printf("after sort:\n");
	showTeacher(q, 3, 3);

	//释放内存
	freeTeacher(&q, 3, 3);
				

	printf("\n");
	system("pause");
	return 0;
}