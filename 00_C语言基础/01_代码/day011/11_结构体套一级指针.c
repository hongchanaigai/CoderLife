/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-06 17:18
 * Last modified  : 2020-08-06 17:18
 * Filename       : 11_结构体套一级指针.c
 * Description    : 
 * *******************************************************/
#include <string.h> //strcpy(),strlen()
#include <stdio.h>
#include <stdlib.h> //malloc(),free()

struct Stu
{
	int age;
	//char name[50];
	char *name;

};

//成员变量指针指向堆区空间
int main()
{
	struct Stu s;
	s.age = 18;

	s.name = (char *)malloc(strlen("huang") + 1); //指向堆区空间
	//s.name = (char *)malloc( (strlen("huang") + 1) * sizeof(char) ); //指向堆区空间
	strcpy(s.name, "huang");

	if(s.name != NULL)
	{
		free(s.name);
		s.name = NULL;
	}

	return 0;
}

//成员变量指针指向栈区空间
int main02()
{
	struct Stu s;
	s.age = 18;

	char buf[50];
	s.name = buf; //指向栈区空间
	strcpy(s.name, "huang");

	return 0;
}

//成员变量指针指向文字常量区的字符串
int main01()
{
	struct Stu s;
	s.age = 18;
	//strcpy(s.name, "huang"); //段错误
	s.name = "huang"; //指针变量保存字符串常量的首地址

	return 0;
}
