//3. ��ϰ�ṹ���������򡡡�
//�Ӽ�������3��ѧ������Ϣ��������ѧ�š��ɼ���������һ���ṹ�������У�
//����ƽ���֣������ɼ��ߵ��������

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
/// �Ӽ�������ѧ����Ϣ
/// </summary>
/// <param name="s">ѧ����Ϣ�ṹ��ָ��</param>
/// <param name="n">ѧ������</param>
void initStu(Stu* s, int n)
{
	if (s == NULL)
	{
		printf("initStu: input error: s == NULL\n");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("\n�������%d��ѧ������Ϣ:\n", i + 1);
		printf("����: \n");
		scanf("%s", s[i].name);

		printf("ѧ��: \n");
		scanf("%d", &s[i].id);

		printf("�ɼ�: \n");
		scanf("%lf", &s[i].score);
	}
}

/// <summary>
/// ����ƽ����
/// </summary>
/// <param name="s">ѧ����Ϣ�ṹ��ָ��</param>
/// <param name="n">ѧ������</param>
/// <returns>�ɹ�����ƽ����,ʧ�ܷ���ʧ����Ϣ��������</returns>
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
/// �������򣬽���
/// </summary>
/// <param name="s">ѧ����Ϣ�ṹ��ָ��</param>
/// <param name="n">ѧ������</param>
void sortStu(Stu* s, int n)
{
	if (s == NULL)
	{
		printf("sortStu: input error: s == NULL\n");
		return;
	}

	//ѡ��
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
/// //��ӡѧ����Ϣ
/// </summary>
/// <param name="s">ѧ����Ϣ�ṹ��ָ��</param>
/// <param name="n">ѧ������</param>
void showStu(Stu* s, int n)
{
	if (s == NULL)
	{
		printf("showStu: input error: s == NULL\n");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("��%d��ѧ����Ϣ: ����%s, ѧ��%d, �ɼ�%lf\n", i + 1, s[i].name, s[i].id, s[i].score);
	}
}

int main(void)
{
	Stu s[3];
	int n = 3;

	//�Ӽ�������ѧ����Ϣ
	initStu(s, n);

	//aveStu(s, 3)��ƽ����
	printf("\nƽ����Ϊ�� %lf\n", aveStu(s, n));

	//�������򣬽���
	sortStu(s, n);

	//��ӡѧ����Ϣ
	showStu(s, n);

	printf("\n");
	system("pause");
	return 0;
}