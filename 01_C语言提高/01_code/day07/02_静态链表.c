#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

typedef struct Node
{
	int data;	//������
	struct Node* next;	//ָ����
}Node;

int main(void)
{
	//��ʼ��3���ṹ�����
	Node n1 = { 1, NULL };
	Node n2 = { 2, NULL };
	Node n3 = { 3, NULL };

	//ָ��ָ��˭,�Ͱ�˭�ĵ�ַ��ֵ��ָ��
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;	//β���

	Node* p = NULL;
	p = &n1;

	while (p != NULL)
	{
		printf("%d\n", p->data);
		//�ڵ�������һ��
		p = p->next;
	}

	printf("\n");
	system("pause");
	return 0;
}