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
	//ǳ��������
	//�ṹ����Ƕ��ָ��,���Ҷ�̬����ռ�
	//ͬ���ͽṹ�������ֵ
	//��ͬ�Ľṹ���Ա����ָ��ͬһ���ڴ�
	/*t2 = t1;*/

	//���,��Ϊ��������,���¿���һ��
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