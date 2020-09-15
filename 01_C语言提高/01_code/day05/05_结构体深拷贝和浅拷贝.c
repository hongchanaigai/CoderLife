#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system(),malloc(),free()
#include <string.h>	//strcpy()

typedef struct Teacher
{
	char* name;
	int age;
}Teacher;

int main(void)
{
	Teacher t1;
	t1.name = (char*)malloc(30);
	if (t1.name != NULL)
	{
		strcpy(t1.name, "name_t1");
	}
	t1.age = 11;

	Teacher t2;
	//浅拷贝条件
	//结构体中嵌套指针,而且动态分配空间
	//同类型结构体变量赋值
	//不同的结构体成员变量指向同一块内存
	/*t2 = t1;*/

	//深拷贝,人为增加内容,重新拷贝一下
	t2 = t1;
	t2.name = (char*)malloc(30);
	if (t2.name != NULL)
	{
		strcpy(t2.name, "name_t1");
	}
	printf("[t2]%s, %d\n", t2.name, t2.age);

	if (t1.name != NULL)
	{
		free(t1.name);
		t1.name = NULL;
	}

	if (t2.name != NULL)
	{
		free(t2.name);
		t2.name = NULL;
	}


	printf("\n");
	system("pause");
	return 0;
}