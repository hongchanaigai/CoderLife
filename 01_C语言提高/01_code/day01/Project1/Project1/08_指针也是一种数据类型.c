#include <stdio.h>
#include <stdlib.h> //system()

int main(void)
{
	int* p = NULL;
	char******* q = NULL;
	printf("sizeof(p) = %d, sizeof(q) = %d\n", sizeof(p), sizeof(q));

	int a = 100;
	int* pa = NULL;
	//ָ��ָ��˭,�Ͱ�˭�ĵ�ַ��ֵ��ָ��
	pa = &a;
	//*Կ��,ͨ��*�����ҵ�ָ��ָ����ڴ�����,�����Ļ����ڴ�
	*pa = 22;

	//*����=���,���ڴ渳ֵ,д�ڴ�
	//*����=�ұ�,ȡ�ڴ��ֵ,���ڴ�
	int b = *pa;
	printf("b = %d\n", b);

	printf("\n");
	system("pause");
	return 0;
}