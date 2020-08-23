#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>	//strcpy(),strlen()

/*
1. C语言没有字符串类型,通过字符数组模拟
2. C语言字符串以字符'\0',或者数字0结尾
*/
int main00(void)
{
	//不指定长度,没有结束符,有多少个元素就有多长
	char buf1[] = { 'a', 'b', 'c' };
	printf("buf1 = %s\n", buf1);	//乱码,没有结束符
	
	//指定长度,后面没有赋值的自动补0
	char buf2[100] = { 'a', 'b', 'c' };
	printf("buf2 = %s\n", buf2);	//正常,指定长度自动在末尾添加结束符

	//所有元素赋值为0
	char buf3[100] = { 0 };

	//char buf4[2] = { '1', '2','3' };	//error,数组越界

	//字符'0',不是结束符(数字0,字符'\0')
	char buf5[10] = { '1', 'a', 'b', '0', '7' };
	printf("buf5 = %s\n", buf5);	//buf5 = 1ab07

	char buf6[10] = { '1', 'a', 'b', 0, '7' };
	printf("buf6 = %s\n", buf6);	//buf6 = 1ab

	char buf7[10] = { '1', 'a', 'b', '\0', '7' };
	printf("buf7 = %s\n", buf6);	//buf7 = 1ab

	//使用字符串初始化,常用
	char buf8[] = "asfhiwajockwpekc";
	printf("strlen(buf8) = %d, sizeof(buf8) = %d\n", strlen(buf8), sizeof(buf8));
	//strlen(buf8) = 16, sizeof(buf8) = 17
	//strlen()测字符串长度,遇到结束符就结束,不包含结束符
	//sizeof()测数组长度,会读取结束符

	//char buf9[100] = "asfhiwajockwpekc";
	//printf("strlen(buf9) = %d, sizeof(buf9) = %d\n", strlen(buf9), sizeof(buf9));
	//strlen(buf9) = 16, sizeof(buf9) = 100

	//printf("test");
	//char str[] = "9";
	//printf("%s\n", str);	//test9
	
	printf("test");
	char str[] = "\0129";	//\012相当于\n
	printf("%s\n", str);	//test换行9

	printf("\n");
	system("pause");
	return 0;
}

int main(void)
{
	char buf[] = "aiugfiwhacowecjpwkdahscf";
	int i = 0;
	int n = strlen(buf);
	//[]方式
	for (i = 0; i < n; ++i)
	{
		printf("%c", buf[i]);
	}
	printf("\n");

	//指针方式
	//数组名字,数组首元素地址
	char* p = NULL;
	p = buf;
	for (i = 0; i < n; ++i)
	{
		printf("%c", p[i]);
	}
	printf("\n");
	
	for (i = 0; i < n; ++i)
	{
		printf("%c", *(p+i));
	}
	printf("\n");

	for (i = 0; i < n; ++i)
	{
		printf("%c", *(buf+i));
	}
	printf("\n");

	//buf和p完全等价吗?
	//p++;	//ok
	//buf++;	//error,buf只是一个常量,不能修改

	printf("\n");
	system("pause");
	return 0;
}