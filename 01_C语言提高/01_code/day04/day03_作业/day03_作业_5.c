/*
5. 有字符串有以下特征（“abcd11111abcd2222abcdqqqqq”）,求写一个函数接口，输出以下结果。
	把字符串替换成（dcba11111dcba2222dcbaqqqqq），并把结果传出。
	要求：
		1. 正确实现接口和功能
		2. 编写测试用例
	src:    原字符串
	dst:    生成的或需要填充的字符串
	sub:    需要查找的子字符串
	new_sub:提换的新子字符串
	return : 0 成功
			-1 失败
int replaceSubstr(char* src, char** dst, char* sub,  char* new_sub)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system(),malloc(),free()
#include <string.h>	//strstr(),strncat(),strlen(),strcat(),strcpy()

/*
* 功能: 替换字符串
* 变量: src	原字符串
		dst	生成的或需要填充的字符串
		sub	需要查找的子字符串
		new_sub	提换的新子字符串
* 返回值: 0	成功
		 非0 失败
*/
int replaceSubstr(char* src/*in*/, char** dst/*out*/, char* sub/*in*/, char* new_sub/*in*/)
{
	// src = "0000abcd11111abcd2222abcdqqqqq"
	// dst = "0000dcba11111dcba2222dcbaqqqqq"
	// sub = "abcd"
	// new_sub = "dcba"
	
	if (src == NULL || dst == NULL || sub == NULL || new_sub == NULL)
	{//出错判断
		printf("replaceSubstr: src/dst/sub/new_sub == NULL\n");
		return -1;
	}

	char tmp[512] = { 0 }; //临时变量, 字符数组
	char* start = src; //记录查找的起点
	char* p = NULL;	//匹配字符串的首地址
	
	do
	{
		// src = "0000abcd11111abcd2222abcdqqqqq"
		// dst = "0000dcba11111dcba2222dcbaqqqqq"
		// sub = "abcd"
		// new_sub = "dcba"
		p = strstr(start, sub);	
		if (p != NULL)
		{
			int len = p - start;	//不匹配的长度,需要拷贝到临时字符数组
			//len = 4,p = src[4],start = src[0]
			if (len > 0)
			{
				//把匹配字符串前面的内容连接过去
				strncat(tmp, start, len);
				//tmp = "0000",start = str[0],len = 4
			}

			strncat(tmp, new_sub, strlen(new_sub)); //追加替换的新串
			//tmp = "0000dcba",strlen(new_sub) = strlen("dcab") = 4

			//更改查找的起点位置
			start = p + strlen(sub);
			//start = str[8],p = str[4],strlen(sub) = strlen("abcd") = 4
		}
		else
		{//没找到
			strcat(tmp, start);	//将原始字符串拷贝,不变
			break;
		}
	} while (*start != '\0');	//等价于start[i] != 0

	//临时变量buf
	char* buf = (char*)malloc(strlen(tmp) + 1);
	strcpy(buf, tmp);
	*dst = buf;	//间接赋值是指针存在的意义

	return 0;
}

void free_dst(char* dst)
{
		free(dst);
		dst = NULL;
}

void free_dst2(char** dst)
{
	char* tmp_dst = *dst;
	if(tmp_dst != NULL)
	{
		free(tmp_dst);
	}
	
	*dst = NULL;
}

int main(void)
{
	char* src = "0000abcd11111abcd2222abcdqqqqq";	//	原始字符串
	char* dst = NULL;	//在replaceSubstr函数中分配空间

	int ret = 0;	//错误码
	ret = replaceSubstr(src/*in*/, &dst/*out*/, "abcd"/*in*/, "dcba"/*in*/);
	
	if (ret != 0)
	{//replaceSubstr函数出错,打印错误信息
		printf("main: replaceSubstr error: %d\n", ret);
		system("pause");	//暂停屏幕
		return ret;
	}

	printf("src = [%s]\n", src);	//原始字符串
	printf("dst = [%s]\n", dst);	//替换后字符串

#if 0
	if (dst != NULL)
	{//释放内存
		free(dst);
		dst = NULL;
	}
#endif	//0

#if 0
	//释放内存
	free_dst(dst);
	dst = NULL;
#endif	//0
	
	//释放内存
	free_dst2(&dst);

	printf("\n");
	system("pause");
	return 0;
}