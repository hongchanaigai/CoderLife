#include <stdio.h>

int main(void)
{
	//��������: һ�������ڴ�ռ����
	//�����൱�����ƺ�,�ڴ��൱�ڷ���
	int a;

	//ֱ�Ӹ�ֵ
	a = 10;

	printf("a = %d\n", a);

	//��Ӹ�ֵ
	printf("&a = %p\n", &a);
	int* p;
	p = &a;
	printf("p = %p\n", p);

	*p = 22;
	printf("*p = %d, a = %d\n", *p, a);

	return 0;
}