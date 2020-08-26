/*
3. ��һ���ַ�����1a2b3d4z����
   Ҫ��дһ������ʵ�����¹��ܣ�
	����1����ż��λ�ַ���ѡ���������һ���ַ���1��
	����2��������λ�ַ���ѡ���������һ���ַ���2��
	����3�����ַ���1���ַ���2��ͨ���������������͸�main������ӡ��
	����4���������ܲ���ͨ����
	int getStr1Str2(char *source, char *buf1, char *buf2);
*/
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>	//strlen()

/*
* ����: ��ż��λ�ַ���ѡ���������һ���ַ���1
*		������λ�ַ���ѡ���������һ���ַ���2
* ����: sourceԭʼ�ַ����׵�ַ
*		buf1ż��λ�ַ����׵�ַ
*		buf2����λ�ַ����׵�ַ
* ����ֵ: 0�ɹ�,��0ʧ��
*/
int getStr1Str2(char* source, char* buf1, char* buf2)
{
	if (source == NULL || buf1 == NULL || buf2 == NULL)
	{
		return -1;
	}

	char* tmp_source = source;
	int n = strlen(tmp_source);
	int i = 0;

	for (i = 0; i < n; ++i)
	{
		if (i % 2 == 0)
		{//ż��λ
			*buf1 = tmp_source[i];
			++buf1;
		}
		else
		{//����λ
			*buf2 = tmp_source[i];
			++buf2;
		}
	}

	//����Ͻ�����
	*buf1 = '\0';
	*buf2 = '\0';

	return 0;
}

int main(void)
{
	char* source = "1a2b3d4z";
	char buf1[10] = { 0 };
	char buf2[10] = { 0 };

	int ret = 0;
	ret = getStr1Str2(source, buf1, buf2);
	if (ret != 0)
	{
		printf("getStr1Str2 error!!!\n");
		return ret;
	}

	printf("source = %s\n", source);
	printf("buf1 = %s\n", buf1);
	printf("buf2 = %s\n", buf2);

	printf("\n");
	system("pause");
	return 0;
}