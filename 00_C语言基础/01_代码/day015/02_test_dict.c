/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-19 15:46
 * Last modified  : 2020-08-19 15:46
 * Filename       : 02_test_dict.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h> //malloc(),free()
#include <string.h> //strlen(),strcpy(),strcmp()
#define MAX 3

struct dict
{
	char *key;
	char *content;
};

void get_dict(struct dict **tmp)
{
	*tmp = (struct dict *)malloc(MAX * sizeof(struct dict));

	//存放第0个单词和翻译
	(*tmp)[0].key = (char *)malloc(strlen("file") + 1);
	strcpy( (*tmp)[0].key, "file");

	(*tmp)[0].content = (char *)malloc(strlen("文件") + 1);
	strcpy( (*tmp)[0].content, "文件");

	//存放地1个单词和翻译
	( *( (*tmp)+1 ) ).key = (char *)malloc(strlen("edit") + 1);
	strcpy( ( *( (*tmp)+1 ) ).key, "edit");

	( *( (*tmp)+1 ) ).content = (char *)malloc(strlen("编辑") + 1);
	strcpy( ( *( (*tmp)+1 ) ).content, "编辑");

	//存放第2个单词和翻译
	(*tmp+2)->key = (char *)malloc(strlen("copy") + 1);
	strcpy( (*tmp+2)->key, "copy");

	(*tmp+2)->content = (char *)malloc(strlen("复制") + 1);
	strcpy( (*tmp+2)->content, "复制");
}

void print_dict(struct dict *tmp)
{
	int i = 0;
	for(i = 0; i < MAX; ++i)
	{
		printf("[%s]%s\n", tmp[i].key, tmp[i].content);
	}
}

void free_dict(struct dict *tmp)
{
	//先释放成员变量
	int i = 0;
	for(i = 0; i < MAX; ++i)
	{
		if(tmp[i].key != NULL) //释放成员变量key
		{
			free(tmp[i].key);
			tmp[i].key = NULL;
		}

		if(tmp[i].content != NULL) //释放成员变量content
		{
			free(tmp[i].content);
			tmp[i].content = NULL;
		}
	}

	//再释放结构体指针变量
	if(tmp != NULL) //释放结构体指针变量
	{
		free(tmp);
		tmp = NULL;
	}
}

int search_dict(char *key, char *content, struct dict *tmp)
{
	int i = 0;
	for(i = 0; i < MAX; ++i)
	{
		if(strcmp(tmp[i].key, key) == 0)
		{
			strcpy(content, tmp[i].content);
			return 1;
		}
	}

	return 0;
}

int main()
{
	struct dict *p = NULL;

	//1. 给p分配空间,分配完空间后,需要设置内容
	get_dict(&p);

	//2. 遍历单词
	print_dict(p);

	//查询单词
	char key[1024]; //单词
	char content[1024]; //翻译

	while(1)
	{
		printf("请输入需要查询的单词: ");
		scanf("%s", key);

		if(strcmp(key, "break") == 0) //输入单词break退出查询
		{
			break;
		}

		//如果有返回真,没有返回假
		int flag = search_dict(key, content, p);
		if(0 == flag)
		{
			printf("没有此单词: %s\n", key);
		}
		else
		{
			printf("[%s]的翻译为: %s\n", key, content);
		}
	}

	//4. 释放空间
	free_dict(p);

	return 0;
}
