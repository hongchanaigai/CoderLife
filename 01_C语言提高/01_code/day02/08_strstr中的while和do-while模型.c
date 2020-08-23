#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>	//strstr(),strlen()

int main00(void)
{
	char* p = "12abcd130abcd74abcd243abcd239asvcah";
	int n = 0;

	do
	{
		p = strstr(p, "abcd");
		if (p != NULL)
		{
			n++;	//找到匹配字符串,累加个数
			//重新设置查找起点
			p += strlen("abcd");

		}
		else
		{	//如果没有匹配字符串,跳出循环
			break;
		}
	} while (*p != '\0');	//如果没有到字符串结尾

	printf("n = %d\n", n);

	printf("\n");
	system("pause");
	return 0;
}

int main01(void)
{
	char* p = "12abcd130abcd74abcd243abcd239asvcah";
	int n = 0;

	while ( p = strstr(p, "abcd") )
	{//能进来肯定有匹配的字符串
		n++;	//没到结束符,累加个数
		p += strlen("abcd");	//重新设置查找起点
		if (*p == '\0')
		{//到结束符,退出循环
			break;
		}
	}

	printf("n = %d\n", n);

	printf("\n");
	system("pause");
	return 0;
}

int my_strstr(char* p, int* n)
{
	//辅助变量
	char* tmp_p = p;
	int tmp_n = 0;

	while ( tmp_p = strstr(tmp_p, "abcd") )
	{//能进来肯定有匹配的字符串
		tmp_n++;	//没到结束符,累加个数
		tmp_p += strlen("abcd");	//重新设置查找起点
		if (*tmp_p == '\0')
		{//到结束符,退出循环
			break;
		}
	}

	//间接赋值
	*n = tmp_n;

	return 0;
}

int main(void)
{
	char* p = "12abcd130abcd74abcd243abcd239asvcah";
	int n = 0;
	int ret = 0;
	ret = my_strstr(p, &n);
	if (ret != 0)
	{
		printf("my_strstr error: %d\n", ret);
		return ret;
	}

	printf("n = %d\n", n);

	printf("\n");
	system("pause");
	return 0;
}