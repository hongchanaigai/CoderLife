/*
7. �ҵ�������ָ���ַ�����λ��
#define NUM(a) (sizeof(a)/sizeof(*a))

char* keywords[] = {
	"while",
	"case",
	"static",
	"do"
};

int searcheKeyTable(const char* table[], const int size, const char* key, int *pos);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>	//strcmp()

#define NUM(a) (sizeof(a)/sizeof(*a))

const char* keywords[] = {
	"while",
	"case",
	"static",
	"do"
};

/// <summary>
/// �ҵ�������ָ���ַ�����λ��
/// </summary>
/// <param name="table">�ַ�������(ָ������)�׵�ַ</param>
/// <param name="size">����Ԫ�ظ���</param>
/// <param name="key">��Ҫ���ҵ��ַ���,��"do"</param>
/// <param name="pos">�ַ����������е��±�λ��,��"do"��keywords[]���±�Ϊ3</param>
/// <returns>�ɹ�����0,ʧ�ܷ��ط�0</returns>
int searcheKeyTable(const char* table[], const int size, const char* key, int* pos)
{
	if (table == NULL || key == NULL)
	{
		printf("searcheKeyTable: input error: table == NULL || key == NULL\n");
		return -1;
	}

	int n = -1;
	for (int i = 0; i < size; ++i)
	{
		if (strcmp(table[i], key) == 0)
		{
			n = i;
			break;
		}
	}

	if (n == -1)	//û���ҵ�ָ���ַ���
	{
		printf("[%s] is not found\n", key);
		return -2;
	}

	*pos = n;

	return 0;
}

int main(void)
{
	int pos = 0;
	int ret = 0;
	char* key = "case";

	ret = searcheKeyTable(keywords, NUM(keywords), key, &pos);
	if (ret != 0)
	{
		printf("main: searcheKeyTable error: %d\n", ret);
		return ret;
	}

	for (int i = 0; i < NUM(keywords); ++i)
	{
		printf("keywords[%d] = %s\n", i, keywords[i]);
	}
	printf("key = %s, pos = %d\n", key, pos);

	printf("\n");
	system("pause");
	return 0;
}