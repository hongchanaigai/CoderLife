#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>	//strcmp()

void print_array(char** p, int np)
{
	if (p == NULL)
	{
		printf("print_array: p == NULL is error\n");
		return;
	}

	char** tmp_p = p;
	int tmp_np = np;

	for (int i = 0; i < tmp_np; ++i)
	{
		printf("p[%d] = [%s]\n", i, tmp_p[i]);
	}
}

void sort_array(char** p, int np)
{
	if (p == NULL)
	{
		printf("sort_array: p == NULL id error\n");
		return;
	}
	char** tmp_p = p;
	int tmp_np = np;

	//选择法排序
	for (int i = 0; i < tmp_np - 1; ++i)
	{
		for (int j = i + 1; j < tmp_np; ++j)
		{
			if (strcmp(tmp_p[i], tmp_p[j]) > 0)
			{//升序
				char* tmp = tmp_p[i];
				tmp_p[i] = tmp_p[j];
				tmp_p[j] = tmp;
			}
		}
	}
}

int main(void)
{
#if 0
	//每个类型都是char*
	char* p0 = "111111111111";
	char* p1 = "000000000000";
	char* p2 = "bbbbbbbbbbbb";
	char* p3 = "aaaaaaaaaaaa";

	//指针数组,指针的数组,它是数组,每个元素都是一个指针char*
	char* p[] = { "111111111111", "000000000000", "bbbbbbbbbbbb","aaaaaaaaaaaa" };
	int np = sizeof(p) / sizeof(p[0]);
	printf("sizeof(p) = [%d], sizeof(p[0]) = [%d]\n", sizeof(p), sizeof(p[0]));

	for (int i = 0; i < np; ++i)
	{
		printf("p[%d] = [%s]\n", i, p[i]);
	}

	char* q[10] = { "111111111111", "000000000000", "bbbbbbbbbbbb","aaaaaaaaaaaa" };
	int nq = sizeof(q) / sizeof(q[0]);
	printf("sizeof(q) = [%d], sizeof(q[0]) = [%d]\n", sizeof(q), sizeof(q[0]));
#endif	//0

#if 0
	//指针数组,指针的数组,它是数组,每个元素都是一个指针char*
	char* p[] = { "111111111111", "000000000000", "bbbbbbbbbbbb","aaaaaaaaaaaa" };
	int np = sizeof(p) / sizeof(p[0]);

	printf("before sorting: \n");
	for (int i = 0; i < np; ++i)
	{
		printf("p[%d] = [%s]\n", i, p[i]);
	}

	//选择法排序
	for (int i = 0; i < np - 1; ++i)
	{
		for (int j = i + 1; j < np; ++j)
		{
			if (strcmp(p[i], p[j]) > 0)
			{//升序
				char* tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}

	printf("\nafter sorting: \n");
	for (int i = 0; i < np; ++i)
	{
		printf("p[%d] = [%s]\n", i, p[i]);
	}
#endif	//0

	//指针数组,指针的数组,它是数组,每个元素都是一个指针char*
	char* p[] = { "111111111111", "000000000000", "bbbbbbbbbbbb","aaaaaaaaaaaa" };
	int np = sizeof(p) / sizeof(p[0]);

	printf("before sorting: \n");
	print_array(p, np);

	sort_array(p, np);

	printf("\nafter sorting: \n");
	print_array(p, np);

	printf("\n");
	system("pause");
	return 0;
}