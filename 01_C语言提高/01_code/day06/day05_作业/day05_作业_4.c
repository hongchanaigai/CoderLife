//4. 重写结构体嵌套一级指针老师和二级指针学生的代码

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),sprintf()
#include <stdlib.h>	//system(),malloc(),free()
#include <string.h>	//strcpy(),strcmp()

//结构体类型，每个导师有三个学生
typedef struct Teacher
{
	char* tName; //导师
	char** stu;  //三个学生
	int age;
}Teacher;

//在createTeacher中分配空间
int createTeacher(Teacher** p/*out*/, int n1, int n2)
{
	if (p == NULL)
	{
		printf("createTeacher: input error:p == NULL\n");
		return -1;
	}

	//n1个导师
	Teacher* tmp_p = NULL;
	tmp_p = (Teacher*)malloc(sizeof(Teacher) * n1);	//Teacher tmp_p[n1];
	if (tmp_p == NULL)
	{
		printf("createTeacher: malloc error: tmp_p == NULL\n");
		return -2;
	}

	//给每个导师内部的姓名,n2个学生分配空间
	for (int i = 0; i < n1; ++i)
	{
		//导师名字
		tmp_p[i].tName = (char*)malloc(20 * sizeof(char));
		if (tmp_p[i].tName == NULL)
		{
			printf("createTeacher: malloc error: tmp_p[i].tName == NULL\n");
			return -2;
		}

		//每个导师有n2个学生
		char** tmp_stu = NULL;
		tmp_stu = (char**)malloc(n2 * sizeof(char*));	//char* tmp_stu[n2];
		if (tmp_stu == NULL)
		{
			printf("createTeacher: malloc error: tmp_stu == NULL\n");
			return -2;
		}

		//给每个导师的n2个学生分配空间
		for (int j = 0; j < n2; ++j)
		{
			tmp_stu[j] = (char*)malloc(20 * sizeof(char));
			if (tmp_stu[j] == NULL)
			{
				printf("createTeacher: malloc error: tmp_stu[j] == NULL\n");
				return -2;
			}
		}

		tmp_p[i].stu = tmp_stu;	//间接赋值,建立指向关系
	}

	//间接赋值,建立指向关系
	*p = tmp_p;

	return 0;
}

//给成员赋值
void initTeacher(Teacher* p, int n1, int n2)
{
	if (p == NULL)
	{
		printf("initTeacher: input error: p == NULL\n");
		return;
	}

	for (int i = 0; i < n1; ++i)
	{
		//导师名字
		char tmp_buf[20] = { 0 };
		sprintf(tmp_buf, "teacher%d%d%d", i, i, i);
		strcpy(p[i].tName, tmp_buf);

		//给每个导师的n2个学生赋值
		for (int j = 0; j < n2; ++j)
		{
			sprintf(tmp_buf, "student%d%d%d%d%d%d", i, i, i, j, j, j);
			strcpy(p[i].stu[j], tmp_buf);
		}

		//导师年龄
		p[i].age = 50 + i;
	}

	return;
}

//打印结构体成员信息
void printTeacher(Teacher* p, int n1, int n2)
{
	if (p == NULL)
	{
		printf("printTeacher: input error: p == NULL\n");
		return;
	}

	//先打印导师
	for (int i = 0; i < n1; ++i)
	{
		printf("%s[%d]:", p[i].tName, p[i].age);

		//再打印学生,每个导师有n2个学生
		for (int j = 0; j < n2; ++j)
		{
			printf("\t%s", p[i].stu[j]);
		}
		printf("\n");
	}

	return;
}


//根据导师名字排序, 降序
void sortTeacher(Teacher* p, int n)
{
	if (p == NULL)
	{
		printf("sortTeacher: input error: p == NULL\n");
		return;
	}

	//选择法排序
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			//降序
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


//释放空间，在函数内部把p赋值为NULL
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
		//释放每个导师名字
		if (tmp[i].tName != NULL)
		{
			free(tmp[i].tName);
			tmp[i].tName = NULL;
		}

		//释放每个导师的n2个学生
		for (int j = 0; j < n2; ++j)
		{
			//释放每个学生
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

	//最后释放tmp,p
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
		*p = NULL;	//注意要把*p赋值为NULL
	}

	return;
}

int main(void)
{
	int ret = 0;
	int n1 = 3; //导师个数
	int n2 = 3; //学生
	Teacher* p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("main: createTeacher err:%d\n", ret);
		return ret;
	}

	initTeacher(p, n1, n2); //给成员赋值

	//打印成员，排序前
	printf("排序前：\n");
	printTeacher(p, n1, n2);


	//根据导师名字排序, 降序
	sortTeacher(p, n1);

	//打印成员，排序后
	printf("\n排序后：\n");
	printTeacher(p, n1, n2);

	//释放空间，在函数内部把p赋值为NULL
	freeTeacher(&p, n1, n2);

	return 0;
}
