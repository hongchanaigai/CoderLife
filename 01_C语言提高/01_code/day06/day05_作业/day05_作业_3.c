//3. 练习结构体数组排序　　
//从键盘输入3个学生的信息（姓名、学号、成绩），存入一个结构体数组中，
//计算平均分，并按成绩高低排序并输出

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),scanf()
#include <stdlib.h>	//system(),malloc(),free()
#include <string.h>

typedef struct Stu
{
	char name[50];
	int id;
	double score;
}Stu;

/// <summary>
/// 从键盘输入学生信息
/// </summary>
/// <param name="s">学生信息结构体指针</param>
/// <param name="n">学生个数</param>
void initStu(Stu* s, int n)
{
	if (s == NULL)
	{
		printf("initStu: input error: s == NULL\n");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("\n请输入第%d个学生的信息:\n", i + 1);
		printf("姓名: \n");
		scanf("%s", s[i].name);

		printf("学号: \n");
		scanf("%d", &s[i].id);

		printf("成绩: \n");
		scanf("%lf", &s[i].score);
	}
}

/// <summary>
/// 计算平均分
/// </summary>
/// <param name="s">学生信息结构体指针</param>
/// <param name="n">学生个数</param>
/// <returns>成功返回平均分,失败返回失败信息及错误码</returns>
double aveStu(Stu* s, int n)
{
	if (s == NULL)
	{
		printf("aveStu: input error: s == NULL\n");
		return -1;
	}

	double sum_score = 0;

	for (int i = 0; i < n; ++i)
	{
		sum_score += s[i].score;
	}

	return sum_score / (n * 1.0);
}

/// <summary>
/// 分数排序，降序
/// </summary>
/// <param name="s">学生信息结构体指针</param>
/// <param name="n">学生个数</param>
void sortStu(Stu* s, int n)
{
	if (s == NULL)
	{
		printf("sortStu: input error: s == NULL\n");
		return;
	}

	//选择法
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (s[i].score < s[j].score)
			{
				Stu tmp_s = s[i];
				s[i] = s[j];
				s[j] = tmp_s;
			}
		}
	}
}

/// <summary>
/// //打印学生信息
/// </summary>
/// <param name="s">学生信息结构体指针</param>
/// <param name="n">学生个数</param>
void showStu(Stu* s, int n)
{
	if (s == NULL)
	{
		printf("showStu: input error: s == NULL\n");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("第%d个学生信息: 姓名%s, 学号%d, 成绩%lf\n", i + 1, s[i].name, s[i].id, s[i].score);
	}
}

int main(void)
{
	Stu s[3];
	int n = 3;

	//从键盘输入学生信息
	initStu(s, n);

	//aveStu(s, 3)：平均分
	printf("\n平均分为： %lf\n", aveStu(s, n));

	//分数排序，降序
	sortStu(s, n);

	//打印学生信息
	showStu(s, n);

	printf("\n");
	system("pause");
	return 0;
}