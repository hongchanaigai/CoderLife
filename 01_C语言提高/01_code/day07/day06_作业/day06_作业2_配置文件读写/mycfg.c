#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>	//printf,fopen,perror,feof,fgets,fclose,fseek,ftell,sprintf,fprintf
#include <stdlib.h>
#include <string.h>	//strlen,strncpy,memset,strstr,strchr,strcat
#include <ctype.h>	//isspace

//文件最大大小
#define MAXSIZE 8 * 1024 //8K

/*
功能：去除字符串两端的空字符,获取非空字符串
参数：
	inbuf： 原始字符串buf首地址
	outbuf：非空字符串buf首地址
返回值：
	成功：0
	失败：非0
*/
int trimSpace(char* inbuf, char* outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		printf("trimSpace: input error: inbuf == NULL || outbuf == NULL\n");
		return -1;
	}

	char* tmp_inbuf = inbuf;	//	临时变量,不修改原始字符串
	int begin = 0;	//字符串开始位置
	int end = strlen(tmp_inbuf) - 1;	//字符串结尾位置
	int n = 0;	//存储非空元素个数

	if (end < 0) 
	{
		printf("trimSpace error: end < 0\n");
		return -2;
	}

	//从左往右移动，如果当前字符为空，而且没有结束
	while (isspace(tmp_inbuf[begin]) && tmp_inbuf[begin] != '\0')
	{
		begin++; //位置向右移动一位
	}

	//从右往左移动，如果当前字符为空
	while (isspace(tmp_inbuf[end]) && end > 0)
	{
		end--; //位置向左移动一位
	}

	if (end == 0)
	{
		printf("trimSpace error: end == 0\n");
		return -2;
	}

	n = end - begin + 1; //非空元素个数

	strncpy(outbuf, tmp_inbuf + begin, n);
	//添加结束符
	outbuf[n] = '\0';

	return 0;
}

//读配置文件
int readCfgFile(char* fileName, char* pKey, char* pValue, int* pLen)
{

	if (fileName == NULL || pKey == NULL || pValue == NULL || pLen == NULL)
	{
		printf("readCfgFile error: fileName == NULL || pKey == NULL || pValue == NULL || pLen == NULL\n");
		return -1;
	}

	FILE* fp = NULL;
	char buf[1024] = { 0 };
	char* tmp_buf = NULL;
	int flag = 0; //如果没有key所对应的value，flag则为0

	//读(二进制)方式打开文件
	fp = fopen(fileName, "rb");
	if (fp == NULL)
	{
		perror("readCfgFile: fopen error");
		return -2;
	}

	//如果文件没有结束
	while (!feof(fp))
	{
		memset(buf, 0, sizeof(buf));
		tmp_buf = fgets(buf, sizeof(buf), fp);
		if (tmp_buf == NULL)
		{
			break;
		}

		//判断每行中是否包含key
		tmp_buf = strstr(buf, pKey);
		if (NULL == tmp_buf)//如果没有包含key
		{
			continue; //跳出本次循环
		}

		//重新设置搜索字符串的位置（跳过key）
		// "k1 = 1111" -> " = 1111"
		tmp_buf = tmp_buf + strlen(pKey);

		//判断是否包含=
		tmp_buf = strchr(tmp_buf, '=');
		if (NULL == tmp_buf)
		{
			continue; //跳出本次循环
		}
		//重新设置搜索字符串的位置(跳过=)
		//"= 1111" -> "   1111  "
		tmp_buf = tmp_buf + 1;

		//获取非空字符，两头堵模型
		if (0 == trimSpace(tmp_buf, pValue))
		{
			//到这，已经找到你所要求的value
			*pLen = strlen(pValue);
			flag = 1;
		}

		break; //很重要
	}

	if (0 == flag)
	{
		printf("no find a key = %s\n", pKey);
		return -6;
	}

	//关闭文件
	if (fp != NULL)
	{
		fclose(fp);
	}

	return 0;
}

//写、修改配置文件
//实现流程
//循环读每一行
//此行包含key，则把key的value修改
//如果所有行都不包含key，则在文件结尾追加： "key = value"
//难点：如何修改
int writeCfgFile(char* fileName, char* pKey, char* pValue, int len)
{
	if (fileName == NULL || pKey == NULL || pValue == NULL)
	{
		printf("writeCfgFile error: fileName == NULL || pKey == NULL || pValue == NULL\n");
		return -1;
	}

	FILE* fp = NULL;
	char tmp_buf[MAXSIZE] = { 0 };
	char line_buf[1024] = { 0 };
	int flag = 0; //0: 不包括key

	//打开文件，读写方式打开，文件不存在，打开失败
	fp = fopen(fileName, "rb+");
	if (fp == NULL) //文件不存在时，新建文件
	{
		//写读方式打开文件，文件不存在则创建
		fp = fopen(fileName, "wb+");
		if (fp == NULL)
		{
			perror("writeCfgFile: fopen error");
			return -2;
		}
	}

	//假如文件存在
	//获取文件内容大小，看是否超出范围

	//把文件光标移动到结尾处
	fseek(fp, 0, SEEK_END);

	//获取文件内容大小
	long size = ftell(fp);

	//如果文件大小超过8k，中断程序
	if (size >= MAXSIZE)
	{
		printf("writeCfgFile: the size > 8k, error\n");
		fclose(fp);
		return -3;
	}

	//把文件光标移动到最开始位置
	fseek(fp, 0, SEEK_SET);

	//循环读每一行
	//此行包含key，则把key的value修改
	//如果所有行都不包含key，则在文件结尾追加： "key = value"
	while (!feof(fp))
	{
		if (NULL == fgets(line_buf, sizeof(line_buf), fp))
		{
			break;
		}

		//此行是否包含key
		if (strstr(line_buf, pKey) != NULL) //包含
		{
			//重写给line_buf格式化
			sprintf(line_buf, "%s = %s\n", pKey, pValue);
			strcat(tmp_buf, line_buf);
			flag = 1;
		}
		else
		{
			strcat(tmp_buf, line_buf);
		}
	}


	if (0 == flag) //文件中没有key值
	{//如果所有行都不包含key，则在文件结尾追加： "key = value"

		//到这一步，文件光标已经移动到结尾处
		//如果此时往文件中写内容，肯定是追加到结尾处
		//格式化方式写文件
		fprintf(fp, "%s = %s\n", pKey, pValue);
	}
	else
	{	//关闭文件
		//重写以写方式打开文件，重写给文件写内容
		if (fp != NULL)
		{
			fclose(fp);
			fp = NULL;
		}

		//写读方式打开文件，文件不存在则创建
		fp = fopen(fileName, "wb+");
		if (fp == NULL)
		{
			perror("writeCfgFile: fopen error");
			return -4;
		}

		//往文件写内容
		fputs(tmp_buf, fp);
	}


	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return  0;
}