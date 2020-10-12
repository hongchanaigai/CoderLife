#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

typedef struct Node
{
	int data;	//数据域
	struct Node* next;	//指针域
}Node;

int main(void)
{
	//初始化3个结构体变量
	Node n1 = { 1, NULL };
	Node n2 = { 2, NULL };
	Node n3 = { 3, NULL };

	//指针指向谁,就把谁的地址赋值给指针
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;	//尾结点

	Node* p = NULL;
	p = &n1;

	while (p != NULL)
	{
		printf("%d\n", p->data);
		//节点往后移一个
		p = p->next;
	}

	printf("\n");
	system("pause");
	return 0;
}