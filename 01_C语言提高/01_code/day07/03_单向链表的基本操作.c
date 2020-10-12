#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

typedef struct Node
{
	int data;	//������
	struct Node* next;	//ָ����
}Node;

/*
1. ����ͷ���
2. �����ͷ����ַ�ɺ���ֵ����
*/
Node* sListCreate()
{
	Node* p_head = NULL;
	
	//ͷ�����Ϊ��־,���洢��Ч����
	p_head = (Node*)malloc(sizeof(Node));
	if (p_head == NULL)
	{
		perror("\nsListCreate: malloc error(p_head)");
		return NULL;
	}

	//��head�ĳ�Ա������ֵ
	p_head->data = -1;
	p_head->next = NULL;

	Node* p_cur = p_head;
	Node* p_new = NULL;

	int data = 0;
	int ret = 0;
	while (1)
	{
		//�ֶ�����ڵ������
		printf("\nplease enter the data(enter -1, exit): ");
		ret = scanf("%d", &data);
		if (-1 == ret)
		{//�������,�˳�
			perror("\nsListCreate: scanf error(data)");
			return NULL;
		}

		if (-1 == data)
		{//����-1,�˳�
			break;
		}

		//���½ڵ㶯̬����ռ�
		p_new = (Node*)malloc(sizeof(Node));
		if (p_new == NULL)
		{//û�ɹ��ٷ���һ��
			continue;
		}

		//���½ڵ��Ա������ֵ
		p_new->data = data;
		p_new->next = NULL;

		//�½ڵ����һ���ڵ㽨����ϵ,��ǰ�ڵ��nextָ��p_new
		p_cur->next = p_new;

		//p_new��nextָ��NULL
		p_new->next = NULL;	//��ʱp_new��β���

		//��ʱ�½ڵ�Ϊ��ǰ�ڵ�,p_cur�ƶ���p_new
		p_cur = p_new;
	}

	return p_head;
}

/*
1. ����ı���
*/
int sListPrint(Node* p_head)
{
	if (p_head == NULL)
	{
		printf("\nsListPrint: p_head == NULL");
		return -1;
	}

	//ȡ����һ����Ч�ڵ�(ͷ����next)
	Node* p_cur = p_head->next;

	printf("\nhead -> ");
	while (p_cur != NULL)
	{
		printf("%d -> ", p_cur->data);

		//�ѵ�ǰ�ڵ������ƶ�һλ
		p_cur = p_cur->next;
	}
	printf("NULL\n");

	return 0;
}

/*
1. ����ڵ�
2. ��ֵΪx�Ľڵ�ǰ����ֵΪy�Ľڵ�;��ֵΪx�Ľڵ㲻����,���ڱ�β����ֵΪy�Ľڵ�
*/
int sListNodeInsert(Node* p_head, int x, int y)
{
	if (p_head == NULL)
	{
		printf("\nsListNodeInsert: p_head == NULL");
		return -1;
	}

	Node* p_pre = p_head;
	Node* p_cur = p_head->next;
	Node* p_new = NULL;

	//���½ڵ㶯̬����ռ�
	p_new = (Node*)malloc(sizeof(Node));
	if (p_new == NULL)
	{
		perror("\nsListNodeInsert: malloc error(p_new)");
		return -2;
	}

	//���½ڵ�ĳ�Ա��ֵ
	p_new->data = y;
	p_new->next = NULL;

	/*����ֵΪx�Ľڵ�*/

	while (p_cur != NULL)
	{
		if (p_cur->data == x)
		{//�ҵ�ֵΪx�Ľڵ�,�˳�ѭ��

			//�ҵ�ֱ�ӽ���ѭ��
			break;
		}

		//��һ���ڵ�͵�ǰ�ڵ�������ƶ�һ��
		p_pre = p_pre->next;
		p_cur = p_cur->next;
	}

	/*
	�������:
	1. �ҵ�ƥ��ڵ�,p_curΪƥ��ڵ�,p_preΪp_cur��һ���ڵ�
	2. û���ҵ�ƥ��ڵ�,p_curΪ�սڵ�,p_preΪβ���
	*/

	/*�����½ڵ�*/

	//��һ���ڵ��nextָ���½ڵ�
	p_pre->next = p_new;

	//�½ڵ��nextָ��ǰ�ڵ�
	p_new->next = p_cur;

	return 0;
}

/*
1. ɾ���ڵ�
2. ɾ����һ��ֵΪx�Ľڵ�
*/
int sListNodeDelete(Node* p_head, int x)
{
	if (p_head == NULL)
	{
		printf("\nsListNodeDelete: p_head == NULL");
		return -1;
	}

	Node* p_pre = p_head;
	Node* p_cur = p_head->next;
	int flag = 0;	//0��ʾû�ҵ�,1��ʾ�ҵ�

	/*����ֵΪx�Ľڵ�*/

	while (p_cur != NULL)
	{
		if (p_cur->data == x)
		{//�ҵ�ֵΪx�Ľڵ�,ɾ���ڵ�
			p_pre->next = p_cur->next;

			//�ͷ�ɾ���Ľڵ���ڴ�ռ�
			free(p_cur);
			p_cur = NULL;

			flag = 1;	//1�����ҵ�
			break;	//�˳�ѭ��
		}

		//��һ���ڵ�͵�ǰ�ڵ�������ƶ�һ��
		p_pre = p_pre->next;
		p_cur = p_cur->next;
	}

	//û���ҵ�ֵΪx�Ľڵ�
	if (0 == flag)
	{
		printf("\nthe node is not found");
		return -2;
	}

	return 0;
}

/*
1. �������
2. �������еĽڵ�,�ͷſռ�
*/
int sListDestroy(Node* p_head)
{
	if (p_head == NULL)
	{
		printf("\nsListDestroy: p_head == NULL");
		return -1;
	}

	Node* p_tmp = NULL;
	int n = 0;

	while (p_head != NULL)
	{
		//����p_head����һ���ڵ�
		p_tmp = p_head->next;

		//�ͷ�p_head�ڵ�
		free(p_head);

		//p_headָ��p_tmp
		p_head = p_tmp;

		//��¼�ͷŽڵ�Ĵ���
		n++;
	}

	printf("\nn = %d", n);

	return 0;
}

int main(void)
{
	Node* p_head = NULL;

	p_head = sListCreate();	//��������
	sListPrint(p_head);	//��������

	//����ڵ�
	sListNodeInsert(p_head, 5, 4);
	printf("\ninsert 4 before 5: ");
	sListPrint(p_head);	//��������

	//ɾ���ڵ�
	sListNodeDelete(p_head, 5);
	printf("\ndelete 5: ");
	sListPrint(p_head);	//��������

	//�������
	sListDestroy(p_head);
	p_head = NULL;

	printf("\n");
	system("pause");
	return 0;
}