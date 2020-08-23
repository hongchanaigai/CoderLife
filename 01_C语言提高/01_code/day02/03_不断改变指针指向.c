#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//perror()
#include <stdlib.h>	//system(),malloc(),free()
#include <string.h>	//strlen(),strcpy()

int main(void)
{
	char* p = NULL;
	char buf[] = "cbasigo";

	//ָ��ջ��
	p = &buf[0];
	printf("p1 = %p, %c\n", p, *p);

	p = &buf[1];
	printf("p2 = %p, %c\n\n", p, *p);

	//����
	int i;
	for (i = 0; i < strlen(buf); ++i)
	{
		//p = &buf[i];
		p = buf + i;
		printf("p%d = %p, %c\n", i, p, *p);
	}

	//ָ�����
	char* q = NULL;
	q = (char*)malloc(100);
	if (q == NULL)
	{
		perror("main malloc");
		return -1;
	}

	strcpy(q, "abcdefg");

	printf("\n");
	for (i = 0; i < strlen(q); ++i)
	{
		p = q + i;
		printf("p%d = %p, %c\n", i, p, *p);
	}

	printf("\n");
	system("pause");
	return 0;
}