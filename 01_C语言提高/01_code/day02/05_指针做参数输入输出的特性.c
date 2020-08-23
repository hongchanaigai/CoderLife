#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//perror()
#include <stdlib.h>	//system(),malloc()
#include <string.h>	//strcpy(),strlen()

void fun(char* buf /* in */)
{
	//给buf指向的内存区域拷贝内容
	strcpy(buf, "abcdefg");
}

void fun2(char* str)
{
	if (str == NULL)
		return;
	strcpy(str, "abcd");
}

void fun3(char** p, int* len /* out */)
{
	if (p == NULL)
		return;

	char* tmp = (char*)malloc(100);
	if (tmp == NULL)
	{
		perror("fun3 malloc");
		return;
	}
	strcpy(tmp, "afdhiwqhfofoqkfper");

	//间接赋值
	*p = tmp;
	*len = strlen(tmp);
}

int main(void)
{
	//输入,主调函数分配内存
	char buf[100] = { 0 };
	fun(buf);
	printf("buf = %s\n", buf);

	char* str = NULL;
	fun2(str);

	//输出,被调用函数分配内存,地址传递
	char* p = NULL;
	int len = 0;
	fun3(&p, &len);
	if (p != NULL)
	{
		printf("p = %s, len = %d\n", p, len);
	}

	printf("\n");
	system("pause");
	return 0;
}