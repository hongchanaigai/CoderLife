#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system(),malloc(),free()
#include <string.h>	//strcpy()

int getMem(char* p)
{
#if 0
	if (p == NULL)
	{
		printf("getMem: [p == NULL] is error\n");
		return -1;
	}
#endif	//0

	p = (char*)malloc(100);
	if (p == NULL)
	{
		printf("getMem: malloc error\n");
		return -1;
	}

	strcpy(p, "aahuaohfeoqf");
	printf("getMem: p = [%s]\n", p);
	
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	return 0;
}

int getMem2(char** p)
{
	if (p == NULL)
	{
		printf("getMem2: p == NULL is error\n");
		return -1;
	}

	char* tmp_p = NULL;
	tmp_p = (char*)malloc(100);
	if (tmp_p == NULL)
	{
		printf("getMem2: malloc error\n");
		return -2;
	}

	strcpy(tmp_p, "afghoqjfoeqjkfpo");
	printf("getMem2: tmp_p = [%s]\n", tmp_p);

	*p = tmp_p;

	return 0;
}

int main(void)
{
	char* p = NULL;
	int ret = 0;

	//ret = getMem(p);	//值传递
	ret = getMem2(&p);	//地址传递
	if (ret != 0)
	{
		//printf("main: getMem error: %d\n", ret);
		printf("main: getMem2 error: %d\n", ret);
		return ret;
	}

	printf("main: p = [%s]\n", p);

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	printf("\n");
	system("pause");
	return 0;
}