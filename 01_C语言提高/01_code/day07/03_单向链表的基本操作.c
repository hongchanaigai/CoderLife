#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

typedef struct Node
{
	int data;	//数据域
	struct Node* next;	//指针域
}Node;

/*
1. 创建头结点
2. 链表的头结点地址由函数值返回
*/
Node* sListCreate()
{
	Node* p_head = NULL;
	
	//头结点作为标志,不存储有效数据
	p_head = (Node*)malloc(sizeof(Node));
	if (p_head == NULL)
	{
		perror("\nsListCreate: malloc error(p_head)");
		return NULL;
	}

	//给head的成员变量赋值
	p_head->data = -1;
	p_head->next = NULL;

	Node* p_cur = p_head;
	Node* p_new = NULL;

	int data = 0;
	int ret = 0;
	while (1)
	{
		//手动输入节点的数据
		printf("\nplease enter the data(enter -1, exit): ");
		ret = scanf("%d", &data);
		if (-1 == ret)
		{//输入出错,退出
			perror("\nsListCreate: scanf error(data)");
			return NULL;
		}

		if (-1 == data)
		{//输入-1,退出
			break;
		}

		//给新节点动态分配空间
		p_new = (Node*)malloc(sizeof(Node));
		if (p_new == NULL)
		{//没成功再分配一次
			continue;
		}

		//给新节点成员变量赋值
		p_new->data = data;
		p_new->next = NULL;

		//新节点和上一个节点建立关系,当前节点的next指向p_new
		p_cur->next = p_new;

		//p_new的next指向NULL
		p_new->next = NULL;	//此时p_new是尾结点

		//此时新节点为当前节点,p_cur移动到p_new
		p_cur = p_new;
	}

	return p_head;
}

/*
1. 链表的遍历
*/
int sListPrint(Node* p_head)
{
	if (p_head == NULL)
	{
		printf("\nsListPrint: p_head == NULL");
		return -1;
	}

	//取出第一个有效节点(头结点的next)
	Node* p_cur = p_head->next;

	printf("\nhead -> ");
	while (p_cur != NULL)
	{
		printf("%d -> ", p_cur->data);

		//把当前节点往下移动一位
		p_cur = p_cur->next;
	}
	printf("NULL\n");

	return 0;
}

/*
1. 插入节点
2. 在值为x的节点前插入值为y的节点;若值为x的节点不存在,则在表尾插入值为y的节点
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

	//给新节点动态分配空间
	p_new = (Node*)malloc(sizeof(Node));
	if (p_new == NULL)
	{
		perror("\nsListNodeInsert: malloc error(p_new)");
		return -2;
	}

	//给新节点的成员赋值
	p_new->data = y;
	p_new->next = NULL;

	/*查找值为x的节点*/

	while (p_cur != NULL)
	{
		if (p_cur->data == x)
		{//找到值为x的节点,退出循环

			//找到直接结束循环
			break;
		}

		//上一个节点和当前节点均往后移动一个
		p_pre = p_pre->next;
		p_cur = p_cur->next;
	}

	/*
	两种情况:
	1. 找到匹配节点,p_cur为匹配节点,p_pre为p_cur上一个节点
	2. 没有找点匹配节点,p_cur为空节点,p_pre为尾结点
	*/

	/*插入新节点*/

	//上一个节点的next指定新节点
	p_pre->next = p_new;

	//新节点的next指向当前节点
	p_new->next = p_cur;

	return 0;
}

/*
1. 删除节点
2. 删除第一个值为x的节点
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
	int flag = 0;	//0表示没找到,1表示找到

	/*查找值为x的节点*/

	while (p_cur != NULL)
	{
		if (p_cur->data == x)
		{//找到值为x的节点,删除节点
			p_pre->next = p_cur->next;

			//释放删除的节点的内存空间
			free(p_cur);
			p_cur = NULL;

			flag = 1;	//1代表找到
			break;	//退出循环
		}

		//上一个节点和当前节点均往后移动一个
		p_pre = p_pre->next;
		p_cur = p_cur->next;
	}

	//没有找到值为x的节点
	if (0 == flag)
	{
		printf("\nthe node is not found");
		return -2;
	}

	return 0;
}

/*
1. 清空链表
2. 销毁所有的节点,释放空间
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
		//保存p_head的下一个节点
		p_tmp = p_head->next;

		//释放p_head节点
		free(p_head);

		//p_head指向p_tmp
		p_head = p_tmp;

		//记录释放节点的次数
		n++;
	}

	printf("\nn = %d", n);

	return 0;
}

int main(void)
{
	Node* p_head = NULL;

	p_head = sListCreate();	//创建链表
	sListPrint(p_head);	//遍历链表

	//插入节点
	sListNodeInsert(p_head, 5, 4);
	printf("\ninsert 4 before 5: ");
	sListPrint(p_head);	//遍历链表

	//删除节点
	sListNodeDelete(p_head, 5);
	printf("\ndelete 5: ");
	sListPrint(p_head);	//遍历链表

	//清空链表
	sListDestroy(p_head);
	p_head = NULL;

	printf("\n");
	system("pause");
	return 0;
}