#include <stdio.h>

char* get_str1(void)
{
	char* p = "abcdef";	//���ֳ�����

	return p;
}

char* get_str2(void)
{
	char* q = "abcdef";	//���ֳ�����

	return q;
}

int main(void)
{
	char* p = NULL;
	char* q = NULL;

	//%s: ָ��ָ���ڴ����������
	//%d: ָ��p�����ֵ
	p = get_str1();
	printf("p = %s, p = %p\n", p, p);
	
	q = get_str2();
	printf("q = %s, q = %p\n", q, q);

	return 0;
}