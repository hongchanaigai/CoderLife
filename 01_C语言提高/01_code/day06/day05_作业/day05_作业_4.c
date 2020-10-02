//4. ��д�ṹ��Ƕ��һ��ָ����ʦ�Ͷ���ָ��ѧ���Ĵ���

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),sprintf()
#include <stdlib.h>	//system(),malloc(),free()
#include <string.h>	//strcpy(),strcmp()

//�ṹ�����ͣ�ÿ����ʦ������ѧ��
typedef struct Teacher
{
	char* tName; //��ʦ
	char** stu;  //����ѧ��
	int age;
}Teacher;

//��createTeacher�з���ռ�
int createTeacher(Teacher** p/*out*/, int n1, int n2)
{
	if (p == NULL)
	{
		printf("createTeacher: input error:p == NULL\n");
		return -1;
	}

	//n1����ʦ
	Teacher* tmp_p = NULL;
	tmp_p = (Teacher*)malloc(sizeof(Teacher) * n1);	//Teacher tmp_p[n1];
	if (tmp_p == NULL)
	{
		printf("createTeacher: malloc error: tmp_p == NULL\n");
		return -2;
	}

	//��ÿ����ʦ�ڲ�������,n2��ѧ������ռ�
	for (int i = 0; i < n1; ++i)
	{
		//��ʦ����
		tmp_p[i].tName = (char*)malloc(20 * sizeof(char));
		if (tmp_p[i].tName == NULL)
		{
			printf("createTeacher: malloc error: tmp_p[i].tName == NULL\n");
			return -2;
		}

		//ÿ����ʦ��n2��ѧ��
		char** tmp_stu = NULL;
		tmp_stu = (char**)malloc(n2 * sizeof(char*));	//char* tmp_stu[n2];
		if (tmp_stu == NULL)
		{
			printf("createTeacher: malloc error: tmp_stu == NULL\n");
			return -2;
		}

		//��ÿ����ʦ��n2��ѧ������ռ�
		for (int j = 0; j < n2; ++j)
		{
			tmp_stu[j] = (char*)malloc(20 * sizeof(char));
			if (tmp_stu[j] == NULL)
			{
				printf("createTeacher: malloc error: tmp_stu[j] == NULL\n");
				return -2;
			}
		}

		tmp_p[i].stu = tmp_stu;	//��Ӹ�ֵ,����ָ���ϵ
	}

	//��Ӹ�ֵ,����ָ���ϵ
	*p = tmp_p;

	return 0;
}

//����Ա��ֵ
void initTeacher(Teacher* p, int n1, int n2)
{
	if (p == NULL)
	{
		printf("initTeacher: input error: p == NULL\n");
		return;
	}

	for (int i = 0; i < n1; ++i)
	{
		//��ʦ����
		char tmp_buf[20] = { 0 };
		sprintf(tmp_buf, "teacher%d%d%d", i, i, i);
		strcpy(p[i].tName, tmp_buf);

		//��ÿ����ʦ��n2��ѧ����ֵ
		for (int j = 0; j < n2; ++j)
		{
			sprintf(tmp_buf, "student%d%d%d%d%d%d", i, i, i, j, j, j);
			strcpy(p[i].stu[j], tmp_buf);
		}

		//��ʦ����
		p[i].age = 50 + i;
	}

	return;
}

//��ӡ�ṹ���Ա��Ϣ
void printTeacher(Teacher* p, int n1, int n2)
{
	if (p == NULL)
	{
		printf("printTeacher: input error: p == NULL\n");
		return;
	}

	//�ȴ�ӡ��ʦ
	for (int i = 0; i < n1; ++i)
	{
		printf("%s[%d]:", p[i].tName, p[i].age);

		//�ٴ�ӡѧ��,ÿ����ʦ��n2��ѧ��
		for (int j = 0; j < n2; ++j)
		{
			printf("\t%s", p[i].stu[j]);
		}
		printf("\n");
	}

	return;
}


//���ݵ�ʦ��������, ����
void sortTeacher(Teacher* p, int n)
{
	if (p == NULL)
	{
		printf("sortTeacher: input error: p == NULL\n");
		return;
	}

	//ѡ������
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			//����
			if (strcmp(p[i].tName, p[j].tName) < 0)
			{
				Teacher tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}

	return;
}


//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
void freeTeacher(Teacher** p, int n1, int n2)
{
	if (p == NULL)
	{
		printf("freeTeacher: input error: p == NULL\n");
		return;
	}

	Teacher* tmp = *p;
	
	for (int i = 0; i < n1; ++i)
	{
		//�ͷ�ÿ����ʦ����
		if (tmp[i].tName != NULL)
		{
			free(tmp[i].tName);
			tmp[i].tName = NULL;
		}

		//�ͷ�ÿ����ʦ��n2��ѧ��
		for (int j = 0; j < n2; ++j)
		{
			//�ͷ�ÿ��ѧ��
			if (tmp[i].stu[j] != NULL)
			{
				free(tmp[i].stu[j]);
				tmp[i].stu[j] = NULL;
			}
		}

		if (tmp[i].stu != NULL)
		{
			free(tmp[i].stu);
			tmp[i].stu = NULL;
		}
	}

	//����ͷ�tmp,p
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
		*p = NULL;	//ע��Ҫ��*p��ֵΪNULL
	}

	return;
}

int main(void)
{
	int ret = 0;
	int n1 = 3; //��ʦ����
	int n2 = 3; //ѧ��
	Teacher* p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("main: createTeacher err:%d\n", ret);
		return ret;
	}

	initTeacher(p, n1, n2); //����Ա��ֵ

	//��ӡ��Ա������ǰ
	printf("����ǰ��\n");
	printTeacher(p, n1, n2);


	//���ݵ�ʦ��������, ����
	sortTeacher(p, n1);

	//��ӡ��Ա�������
	printf("\n�����\n");
	printTeacher(p, n1, n2);

	//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
	freeTeacher(&p, n1, n2);

	return 0;
}
