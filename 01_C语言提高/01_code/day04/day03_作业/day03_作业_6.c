/*
6. 有一个字符串符合以下特征（“abcdef,acccd,eeee,aaaa,e3eeee,ssss,”）

	写两个函数(API)，输出以下结果
	第一个API(第二种内存模型： 二维数组)
	1)以逗号分隔字符串，形成二维数组，并把结果传出
	2)把二维数组行数运算结果也传出
	int spitString(const char *str, char c, char buf[10][30], int* count);

	第二个API(第三种内存模型：动态生成二维内存)
		1)以逗号分隔字符串，形成一个二级指针。
		2)把一共拆分多少行字符串个数传出
		int spitString2(const char* str, char c, char** myp, int* count);

	要求：
		1, 能正确表达功能的要求，定义出接口。
		2, 正确实现接口和功能.
		3, 编写正确的测试用例.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system(),malloc(),free()
#include <string.h>	//strchr(),strncpy(),strcpy()

int spitString(const char* str, char c, char buf[10][30], int* count)
{
	if (str == NULL || count == NULL)
	{
		printf("spitString: str/count == NULL\n");
		return -1;
	}
	
	//str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
	const char* start = str;
	char* p = NULL;
	int i = 0;	//buf[i]

	do
	{//找到
		p = strchr(satrt, c);
		if (p != NULL)
		{
			//str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
			int len = p - satrt;	//len = 6,p = str[6],start = str[0]
			if (len > 0)
			{
				strncpy(buf[i], start, len);	//buf[0] = "abcdef"
				//添加结束符
				buf[i][len] = '\0';

				++i;
			}
			//重新设置起点位置
			//str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
			start = p + 1;	//start = str[7],p = str[6]
		}
		else
		{//没找到
			strcpy(buf[i], start);	//start = str[30],buf[5] = "ssss"
			++i;	//再加一次,保证总数count+1,保证最后一次打印出来
			break;
		}
	} while (*satrt != 0);
	
	if(i == 0)
	{
		printf("spitString: i == 0\n");
		return -2;
	}

	*count = i; //有多少行字符串

	return 0;
}

char** getMem(int count)
{
	char** buf = NULL;	//char* buf[count]
	buf = (char**)malloc(count * sizeof(char*)); //char* buf[]
	if (buf == NULL)
	{
		printf("getMem: malloc error, buf == NULL\n");
		return NULL;
	}

	//每个元素的空间
	for (int i = 0; i < count; ++i)
	{
		buf[i] = (char*)malloc(30 * sizeof(char)); //char buf[]
		if (buf[i] == NULL)
		{
			printf("getMem: malloc error, buf[i] == NULL\n");
			return NULL;
		}
	}

	return buf;
}

void getMemFree(char*** buf, int count)
{
	if (buf == NULL)
	{
		printf("getMemFree: buf == NULL\n");
		return;
	}

	char** tmp = *buf;

	for (int i = 0; i < count; ++i)
	{
		if (tmp[i] != NULL)
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}
	}

	free(tmp);
	*buf = NULL;
}

int spitString2(const char* str, char c, char** buf, int* count)
{
	if (str == NULL || count == NULL)
	{
		return -1;
	}

	char* start = str;
	char* p = NULL;
	int i = 0; //第几行

	do
	{
		//"abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
		p = strchr(start, c);
		if (p != NULL)
		{
			int len = p - start;
			if (len > 0)
			{
				strncpy(buf[i], start, len);
				//添加结束符
				buf[i][len] = '\0';

				i++;
			}
			start = p + 1;
		}
		else
		{
			strcpy(buf[i], start);	//start = str[30],buf[5] = "ssss"
			++i;	//再加一次,保证总数count+1,保证最后一次打印出来
			break;
		}
	} while (*start != 0);

	*count = i; //有多少行字符串

	return 0;
}

int main(void)
{
#if 0
	char* str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	char buf[10][30] = { 0 };
	int count = 0;
	
	int ret = 0;
	ret = spitString(str, ',', buf, &count);
	if (ret != 0)
	{
		printf("main: spitString error: %d\n", ret);
		return ret;
	}
	
	for (int i = 0; i < count; ++i)
	{
		printf("buf[%d] = [%s]\n", i, buf[i]);
	}

#endif	//0

	char* str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	char** buf = NULL;
	
	buf = getMem(6);
	if(buf == NULL)
	{
		printf("main: buf == NULL\n");
		return -1;
	}
	//char** buf = getMem(10); //动态打造二维数组
	
	int count = 0;

	int ret = 0;
	ret = spitString2(str, ',', buf, &count);
	if (ret != 0)
	{
		printf("main: spitString2 error: %d\n", ret);
		return ret;
	}

	for (int i = 0; i < count; ++i)
	{
		printf("buf[%d] = [%s]\n", i, buf[i]);
	}
	
	//释放内存
	for(int i = 0; i < count; ++i)
	{
		free(buf[i]);
		buf[i] = NULL;
	}
	
	if(buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
	//getMemFree(&buf, count);

	printf("\n");
	system("pause");
	return 0;
}