#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> //strcpy()
#include <stdlib.h> //system(),malloc(),free()

char* get_str()
{
	char str[] = "abcdefgh"; //ջ��
	printf("str = %s\n", str);
	return str;
}

char* get_str2()
{
	char* tmp = (char*)malloc(100);
	if (tmp == NULL) //����ʧ��
	{
		return NULL;
	}

	strcpy(tmp, "abcdefgh");
	return tmp;
}

int main(void)
{
	char buf[128] = { 0 };

	//strcpy(buf, get_str());
	//printf("buf = %s\n", buf); //����,��ȷ��

	//char* p = NULL;
	//p = get_str();
	//printf("p = %s\n", p); //����,��ȷ��

	char* p = NULL;
	p = get_str2();
	if (p != NULL)
	{
		printf("p = %s\n", p);
		free(p);
		p = NULL;
	}

	printf("\n");
	system("pause");
	return 0;
}