/*
4. 键值对（“key = value”）字符串，在开发中经常使用
	要求1：请自己定义一个接口，实现根据key获取.
	要求2：编写测试用例。
	要求3：键值对中间可能有n多空格，请去除空格

	注意：键值对字符串格式可能如下：
	"key1 = value1"
	"key2 =       value2"
	"key3  = value3"
	"key4        = value4"
	"key5   =   "
	"key6   ="

	int getKeyByValue(char *keyvaluebuf,  char *keybuf,  char *valuebuf, int * valuebuflen);
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	//system()
#include <string.h>	//strlen(),strncpy(),strstr()
#include <ctype.h>	//isspace()

/*
* 功能: 获取非空字符串
* 参数: inbuf原始字符串首地址
*		outbuf非空字符串首地址
* 返回值: 0成功,非0失败
*/
int trimSpace(char* inbuf, char* outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		printf("trimSpace: input error\n");
		return -1;
	}

	char* tmp_inbuf = inbuf;	//辅助变量,不直接使用形参
	int begin = 0;	//字符串首元素下标
	int end = strlen(tmp_inbuf) - 1;	//字符串尾元素下标
	if (end < 0)
	{
		printf("trimSpace: end < 0\n");
		return -2;
	}

	//从首元素开始向右走
	while (isspace(tmp_inbuf[begin]) && tmp_inbuf[begin] != '\0')
	{
		begin++;
	}

	//从尾元素开始向左走
	while (isspace(tmp_inbuf[end]) && end > 0)
	{
		end--;
	}

	if (end == 0)
	{
		printf("trimSpace: end == 0\n");
		return -3;
	}

	int n = end - begin + 1;

	strncpy(outbuf, tmp_inbuf + begin, n);
	outbuf[n] = '\0';

	return 0;
}

/*
* 功能: 根据key值获取对应的value值
* 参数: keyvaluebuf,键值对（“key = value”）字符串首地址
*		keybuf,key值字符串首地址
*		valuebuf,value值字符串首地址
*		valuebuflen,value值字符串长度
* 返回值: 0成功,非0失败
*/
int getKeyByValue(char* keyvaluebuf, char* keybuf, char* valuebuf, int* valuebuflen)
{
	/*
	* keyvaluebuf = "key1 =   value1"
	* keybuf = "key1"
	*/
	if (keyvaluebuf ==NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL)
	{
		printf("getKeyByValue: input error\n");
		return -1;
	}

	char* tmp_keykeyvaluebuf = keyvaluebuf;
	char* tmp_keybuf = keybuf;

	//查找匹配的keybuf
	//"key1 =   value1"找"key1",找到返回首地址
	char* p = NULL;
	p = strstr(tmp_keykeyvaluebuf, tmp_keybuf);
	if (p == NULL)
	{//没找到匹配的keybuf,即没找到"key1"
		printf("getKeyByValue: can not find keybuf\n");
		return -2;
	}
	//如果找到,重新设置起点位置,跳过keybuf,即跳过"key1"
	//p = " =   value1"
	//"key1 =   value1" --> " =   value1"
	p += strlen(tmp_keybuf);

	//查找"="
	p = strstr(p, "=");
	if (p == NULL)
	{//没找到"="
		printf("getKeyByValue: can not find =\n");
		return -3;
	}
	//找到"=",跳过"="
	//p = "   value1"
	//" =   value1" --> "   value1"
	p += strlen("=");

	//取非空字符串,即valuebuf
	int ret = 0;
	ret = trimSpace(p, valuebuf);
	if (ret != 0)
	{
		printf("getKeyByValue: trimSpace error: %d\n", ret);
		return ret;
	}

	//获取valuebuf的长度
	*valuebuflen = strlen(valuebuf);

	return 0;
}

int main(void)
{
	char* keyvaluebuf = "key1 =   value1";
	char* keybuf = "key1";

	//char* keyvaluebuf = "key4        = value4";
	//char* keybuf = "key4";

	//char* keyvaluebuf = "key4        = value4";
	//char* keybuf = "key2";

	//char* keyvaluebuf = "key4        * value4";
	//char* keybuf = "key4";

	//char* keyvaluebuf = "key4        =            ";
	//char* keybuf = "key4";

	char valuebuf[50] = { 0 };
	int valuebuflen = 0;

	int ret = 0;
	ret = getKeyByValue(keyvaluebuf, keybuf, valuebuf, &valuebuflen);
	if (ret != 0)
	{
		printf("getKeyByValue error: %d\n", ret);
		return ret;
	}

	printf("keyvaluebuf: [%s]\n", keyvaluebuf);
	printf("keybuf: [%s]\n", keybuf);
	printf("valuebuf: [%s]\n", valuebuf);
	printf("valuebuflen: [%d]\n", valuebuflen);

#if 0	//条件编译
	char* inbuf = "          aidheidhi          ";
	char outbuf[50] = { 0 };

	int ret1 = 0;
	ret1 = trimSpace(inbuf, outbuf);

	if (ret1 != 0)
	{
		printf("trimSpace error: %d\n", ret1);
		return ret1;
	}

	printf("inbuf = [%s]\n", inbuf);
	printf("outbuf = [%s]\n", outbuf);
#endif	//条件编译结束

	printf("\n");
	system("pause");
	return 0;
}