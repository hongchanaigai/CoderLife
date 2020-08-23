#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>	//strcpy(),strlen()

/*
1. C����û���ַ�������,ͨ���ַ�����ģ��
2. C�����ַ������ַ�'\0',��������0��β
*/
int main00(void)
{
	//��ָ������,û�н�����,�ж��ٸ�Ԫ�ؾ��ж೤
	char buf1[] = { 'a', 'b', 'c' };
	printf("buf1 = %s\n", buf1);	//����,û�н�����
	
	//ָ������,����û�и�ֵ���Զ���0
	char buf2[100] = { 'a', 'b', 'c' };
	printf("buf2 = %s\n", buf2);	//����,ָ�������Զ���ĩβ��ӽ�����

	//����Ԫ�ظ�ֵΪ0
	char buf3[100] = { 0 };

	//char buf4[2] = { '1', '2','3' };	//error,����Խ��

	//�ַ�'0',���ǽ�����(����0,�ַ�'\0')
	char buf5[10] = { '1', 'a', 'b', '0', '7' };
	printf("buf5 = %s\n", buf5);	//buf5 = 1ab07

	char buf6[10] = { '1', 'a', 'b', 0, '7' };
	printf("buf6 = %s\n", buf6);	//buf6 = 1ab

	char buf7[10] = { '1', 'a', 'b', '\0', '7' };
	printf("buf7 = %s\n", buf6);	//buf7 = 1ab

	//ʹ���ַ�����ʼ��,����
	char buf8[] = "asfhiwajockwpekc";
	printf("strlen(buf8) = %d, sizeof(buf8) = %d\n", strlen(buf8), sizeof(buf8));
	//strlen(buf8) = 16, sizeof(buf8) = 17
	//strlen()���ַ�������,�����������ͽ���,������������
	//sizeof()�����鳤��,���ȡ������

	//char buf9[100] = "asfhiwajockwpekc";
	//printf("strlen(buf9) = %d, sizeof(buf9) = %d\n", strlen(buf9), sizeof(buf9));
	//strlen(buf9) = 16, sizeof(buf9) = 100

	//printf("test");
	//char str[] = "9";
	//printf("%s\n", str);	//test9
	
	printf("test");
	char str[] = "\0129";	//\012�൱��\n
	printf("%s\n", str);	//test����9

	printf("\n");
	system("pause");
	return 0;
}

int main(void)
{
	char buf[] = "aiugfiwhacowecjpwkdahscf";
	int i = 0;
	int n = strlen(buf);
	//[]��ʽ
	for (i = 0; i < n; ++i)
	{
		printf("%c", buf[i]);
	}
	printf("\n");

	//ָ�뷽ʽ
	//��������,������Ԫ�ص�ַ
	char* p = NULL;
	p = buf;
	for (i = 0; i < n; ++i)
	{
		printf("%c", p[i]);
	}
	printf("\n");
	
	for (i = 0; i < n; ++i)
	{
		printf("%c", *(p+i));
	}
	printf("\n");

	for (i = 0; i < n; ++i)
	{
		printf("%c", *(buf+i));
	}
	printf("\n");

	//buf��p��ȫ�ȼ���?
	//p++;	//ok
	//buf++;	//error,bufֻ��һ������,�����޸�

	printf("\n");
	system("pause");
	return 0;
}