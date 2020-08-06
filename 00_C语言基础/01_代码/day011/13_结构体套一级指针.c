/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-06 17:46
 * Last modified  : 2020-08-06 17:46
 * Filename       : 13_结构体套一级指针.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //strcpy()
#include <stdlib.h> //malloc(),free()

struct Stu
{
	int age;
	char *name;
};

int main()
{
	struct Stu *p;

	//需要给p分配内存
	p = (struct Stu *)malloc(sizeof(struct Stu));
	if(p == NULL) //分配失败
	{
		printf("malloc error!!!\n");
		return 0; //退出程序
	}

	p->age = 18;
	//需要给p->name分配空间
	p->name = (char *)malloc( strlen("huang") + 1 );
	strcpy(p->name, "huang");
	printf("%d, %s\n", p->age, p->name);

	if(p->name != NULL)
	{
		free(p->name); //先释放p->name指向的堆区空间
		p->name = NULL;
	}

	if(p != NULL)
	{
		free(p); //再释放p指向的堆区空间
		p = NULL;
	}

	return 0;
}
