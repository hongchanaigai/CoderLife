#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>	//memcpy(),strcpy()

int main(void)
{
	void* p = 0x1122;
	char buf[1024] = "afhueahfiehflasmclsd";
	p = buf;	//ָ�����ָ��,ת��Ϊʵ������ָ��
	printf("p = %s\n", (char*)p);

	int a[100] = { 1, 2, 3, 4 };
	p = a;
	int i;
	for (i = 0; i < 4; ++i)
	{
		printf("%d ", *( (int*)p + i ) );
	}
	printf("\n");

	int b[3] = { 1, 2, 3 };
	int c[3];
	memcpy(c, b, sizeof(b));
	for (i = 0; i < 3; ++i)
	{
		printf("%d ", c[i]);
	}
	printf("\n");

	char str[] = "asfhiqhfoefjecmpw";
	char dst[100];
	memcpy(dst, str, sizeof(str));
	printf("dst = %s\n", dst);

	//char* q = NULL;
	//��qָ����ڴ�����ֵ
	//strcpy(q, "12345");	//�δ���,qΪҰָ��
	//�����������: 
	char* q = NULL;
	char str2[100] = { 0 };
	q = str2;	//��qָ��str2,��ʱq������Ұָ��
	strcpy(q, "12345");
	printf("q = %s\n", q);

	printf("\n");
	system("pause");
	return 0;
}