#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>	//strcpy()

int main(void)
{
	char* p = NULL;
	printf("p1 = %p\n", p);
	//�ı�ָ�����p��ֵ
	char buf[] = "abcde";
	p = buf;
	printf("p2 = %p\n", p);

	//ָ�����,��ָ��ָ����ڴ�,����������
	p = p + 1;	//�ı���ָ�������ֵ,�ı���ָ���ָ��
	printf("p3 = %p\n", p);
	printf("buf1 = %s\n", buf);

	printf("*p = %c\n", *p);

	//�ı�ָ��ָ����ڴ�,������Ӱ��ָ�����p��ֵ
	printf("\n");
	buf[1] = '1';
	printf("p4 = %p\n", p);
	printf("buf2 = %s\n", buf);

	*p = 'm';
	printf("p5 = %p\n", p);
	printf("buf3 = %s\n", buf);

	//д�ڴ�ʱ,һ��Ҫȷ���ڴ��д
	char* str1 = "shodfjepvkeprfjvoahcodjc";	//���ֳ�����,�ڴ治�����޸�
	//str1[2] = '2';	//error,���ֳ��������ݲ������޸�

	char str2[] = "shodfjepvkeprfjvoahcodjc";	//ջ��,�ڴ������޸�
	str2[2] = '2';	//ok,ջ�����ݿ����޸�

	char* q1 = NULL;
	//strcpy()�����Ĺ���: ��q1ָ����ڴ����򿽱�����
	//q1 = str2;	//ȷ��ָ���Ͳ��ᷢ������
	//strcpy(q1, "1111");	//error

	printf("\n");
	system("pause");
	return 0;
}