#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),sprintf()
#include <stdlib.h>	//system(),malloc(),free()
#include <string.h>	//strcpy()

#if 0
int main00(void)
{
	char* p0 = NULL;
	p0 = (char*)malloc(50);
	strcpy(p0, "sfsheifhw");

	//10个char*,每一个值都是空
	char* p[10] = { 0 };
	for (int i = 0; i < 10; ++i)
	{
		p[i] = (char*)malloc(50);
		strcpy(p[i], "agfiehfowhcowic");
	}

	int a[10];
	int* pa = (int*)malloc(10 * sizeof(int));

	//动态分配一个数组,每个元素都是char*
	//char *ch[3]
	int n = 3;
	char** buf = (char**)malloc(n * sizeof(char*));	//char* buf[3]
	if (buf == NULL)
	{
		printf("main: malloc error! buf == NULL is error!\n");
		return -1;
	}

	for (int i = 0; i < n; ++i)
	{
		buf[i] = (char*)malloc(30 * sizeof(char));
		char str[30] = { 0 };
		sprintf(str, "test%d", i);
		strcpy(buf[i], str);
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%s\n", buf[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		if (buf[i] != NULL)
		{
			free(buf[i]);
			buf[i] = NULL;
		}
	}

	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}

	printf("\n");
	system("pause");
	return 0;
}
#endif	//0

char** getMem(int n)
{
	char** buf = (char**)malloc(n * sizeof(char*));	//char* buf[3]
	if (buf == NULL)
	{
		printf("getMem: malloc error!\n");
		return NULL;
	}

	for (int i = 0; i < n; ++i)
	{
		buf[i] = (char*)malloc(30 * sizeof(char));
		char str[30] = { 0 };
		sprintf(str, "test%d", i);
		strcpy(buf[i], str);
	}

	return buf;
}

void print_buf(char** buf, int n)
{
	if (buf == NULL)
	{
		printf("print_buf: buf == NULL is error!\n");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%s\n", buf[i]);
	}

}

void free_buf(char** buf, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (buf[i] != NULL)
		{
			free(buf[i]);
			buf[i] = NULL;
		}
	}

	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
}

int main(void)
{
	char** buf = NULL;
	int n = 3;

	buf = getMem(n);
	if (buf == NULL)
	{
		printf("main: getMem error!\n");
		return -1;
	}

	print_buf(buf, n);

	free_buf(buf, n);
	buf = NULL;

	printf("\n");
	system("pause");
	return 0;
}