#include <stdio.h>
#include <stdlib.h> //system()

int main(void)
{
	int a;		//���߱�����,����4�ֽ�
	int b[10];	//���߱�����,����4 * 10�ֽ�

	/*
	���͵ı���:�̶��ڴ���С����
	����ͨ��sizeof()����
	*/
	printf("sizeof(a) = %d, sizeof(b) = %d\n", sizeof(a), sizeof(b));
	
	//��ӡ��ַ
	/*
	b,&b���������Ͳ�һ��
	1. b, ������Ԫ�ص�ַ,һ��Ԫ��4�ֽ�, +1����, +4�ֽ�
	2. &b, ����������׵�ַ,һ������4*10 = 40�ֽ�, +1����, +40�ֽ�
	*/
	printf("b = %p, &b = %p\n", b, &b);
	printf("b+1 = %p, &b+1 = %p\n", b+1, &b+1);

	//ָ�����ͳ���,32λ����,����Ϊ4�ֽ�,64λ����,����Ϊ8�ֽ�
	char*** p1 = NULL;
	int* p2 = NULL;
	printf("p1 = %d, p2 = %d\n", sizeof(p1), sizeof(p2));

	//printf("\n");
	//system("pause");
	return 0;
}