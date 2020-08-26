/*
3. 有一个字符串“1a2b3d4z”；
   要求写一个函数实现如下功能：
	功能1：把偶数位字符挑选出来，组成一个字符串1。
	功能2：把奇数位字符挑选出来，组成一个字符串2。
	功能3：把字符串1和字符串2，通过函数参数，传送给main，并打印。
	功能4：主函数能测试通过。
	int getStr1Str2(char *source, char *buf1, char *buf2);
*/
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>	//strlen()

/*
* 功能: 把偶数位字符挑选出来，组成一个字符串1
*		把奇数位字符挑选出来，组成一个字符串2
* 参数: source原始字符串首地址
*		buf1偶数位字符串首地址
*		buf2奇数位字符串首地址
* 返回值: 0成功,非0失败
*/
int getStr1Str2(char* source, char* buf1, char* buf2)
{
	if (source == NULL || buf1 == NULL || buf2 == NULL)
	{
		return -1;
	}

	char* tmp_source = source;
	int n = strlen(tmp_source);
	int i = 0;

	for (i = 0; i < n; ++i)
	{
		if (i % 2 == 0)
		{//偶数位
			*buf1 = tmp_source[i];
			++buf1;
		}
		else
		{//奇数位
			*buf2 = tmp_source[i];
			++buf2;
		}
	}

	//添加上结束符
	*buf1 = '\0';
	*buf2 = '\0';

	return 0;
}

int main(void)
{
	char* source = "1a2b3d4z";
	char buf1[10] = { 0 };
	char buf2[10] = { 0 };

	int ret = 0;
	ret = getStr1Str2(source, buf1, buf2);
	if (ret != 0)
	{
		printf("getStr1Str2 error!!!\n");
		return ret;
	}

	printf("source = %s\n", source);
	printf("buf1 = %s\n", buf1);
	printf("buf2 = %s\n", buf2);

	printf("\n");
	system("pause");
	return 0;
}