/*
4. 动手重新写一下加密解密案例，例子参考《04_加密解密文件》
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),scanf(),perror(),fopen(),fclose(),feof(),fread(),fwrite()
#include <stdlib.h>	//system()
#include <string.h>	//strcmp()

#include "des.h"	//DesEnc_raw(),DesEnc(),DesDec_raw(),DesDec()
#define SIZE 1024 * 4	//4K

/// <summary>
/// 提示菜单
/// </summary>
void myMenu()
{
	printf("\n************************************");
	printf("\n\t1. encrypt a file");
	printf("\n\t2. decrypt a file");
	printf("\n\t3. clear the screen");
	printf("\n\t4. exit");
	printf("\n************************************");
}

/// <summary>
/// 加密文件
/// </summary>
void encryptFile()
{
	char src_path[512] = { 0 };	//源文件文件路径
	char dst_path[512] = { 0 };	//目的文件文件路径
	int ret = 0;	//函数返回值,检查调用函数是否出错

	FILE* src_fp = NULL;	//源文件文件指针
	FILE* dst_fp = NULL;	//目的文件文件指针

	unsigned char clear_buf[SIZE] = { 0 };	//明文
	int clear_len = 0;	//明文长度

	unsigned char cipher_buf[SIZE] = { 0 };	//密文
	int cipher_len = 0;	//密文长度

	/*提示输入加密前后的两个文件*/

	//提示输入需要加密的文件
	printf("\nplease enter the file you want to encrypt: ");
	ret = scanf("%s", src_path);
	if (-1 == ret)
	{
		perror("\nencryptFile: scanf error(src_path)");
		return;
	}

	//提示输入保存加密后结果的文件
	printf("\nplease enter the file you want to save the result: ");
	ret = scanf("%s", dst_path);
	if (-1 == ret)
	{
		perror("\nencryptFile: scanf error(dst_path)");
		return;
	}

	//提示两个文件名不能一样
	ret = strcmp(src_path, dst_path);
	if (0 == ret)
	{
		printf("\nthe file name can no be the same");
		return;
	}

	/*打开文件*/

	//读(二进制)方式打开需要加密的文件
	src_fp = fopen(src_path, "rb");
	if (src_fp == NULL)
	{
		perror("\nencryptFile: fopen error(src_path)");
		return;
	}

	//写(二进制)方式打开保存加密后结果的文件
	dst_fp = fopen(dst_path, "wb");
	if (dst_fp == NULL)
	{
		perror("\nencryptFile: fopen error(dst_path)");
		//此时源文件已经打开,需要关闭
		goto CloseSrcFile;
		return;
	}

	/*加密文件*/
	/*
	1. 从源文件中读取数据
	2. 4k: DesEnc_raw()
	3. <4k: DesEnc()
	*/

	while (!feof(src_fp))	//文件没有结束
	{
		/*
		1. 从文件中读取内容
		2. clear_buf: 存放文件内容的buf
		3. 1: 每次读1个字节
		4. SIZE: 一次读4k块内存,读取内容的大小: SIZE * 1
		5. 返回值: 成功读取内容的块数
		*/
		clear_len = fread(clear_buf, 1, SIZE, src_fp);
		if (clear_len < SIZE)	//如果读取内容<4k，跳出循环
		{
			break;
		}

		//size = 4k数据的加密处理
		//把明文clear_buf(长度为clear_len)加密为密文cipher_buf(长度为cipher_len)
		ret = DesEnc_raw(clear_buf, clear_len, cipher_buf, &cipher_len);
		if (ret != 0)
		{
			printf("\nencryptFile: DesEnc_raw error: %d", ret);
			//此时源文件,目的文件已经打开,需要关闭
			goto CloseSrcFile;
			goto CloseDstFile;
			return;
		}

		//把密文cipher_buf(长度为cipher_len)写到文件dst_fp中
		ret = fwrite(cipher_buf, 1, cipher_len, dst_fp);
		if (ret != cipher_len)
		{
			printf("\nwrite to file failed(size == 4k)");
			//此时源文件,目的文件已经打开,需要关闭
			goto CloseSrcFile;
			goto CloseDstFile;
			return;
		}
	}

	//size < 4k的处理
	//把明文clear_buf(长度为clear_len)加密为密文cipher_buf(长度为cipher_len)
	ret = DesEnc(clear_buf, clear_len, cipher_buf, &cipher_len);
	if (ret != 0)
	{
		printf("encryptFile: DesEnc error: %d\n", ret);
		//此时源文件,目的文件已经打开,需要关闭
		goto CloseSrcFile;
		goto CloseDstFile;
		return;
	}

	//把密文cipher_buf(长度为cipher_len)写到文件wFp中
	ret = fwrite(cipher_buf, 1, cipher_len, dst_fp);
	if (ret != cipher_len)
	{
		printf("\nwrite to file failed(size < 4k)");
		//此时源文件,目的文件已经打开,需要关闭
		goto CloseSrcFile;
		goto CloseDstFile;
		return;
	}

	/*关闭文件*/

CloseSrcFile:
	if (src_fp != NULL)
	{
		fclose(src_fp);
	}

CloseDstFile:
	if (dst_fp != NULL)
	{
		fclose(dst_fp);
	}
}

/// <summary>
/// 解密文件
/// </summary>
void decryptFile()
{
	char src_path[512] = { 0 };	//源文件文件路径
	char dst_path[512] = { 0 };	//目的文件文件路径
	int ret = 0;	//函数返回值,检查调用函数是否出错

	FILE* src_fp = NULL;	//源文件文件指针
	FILE* dst_fp = NULL;	//目的文件文件指针

	unsigned char clear_buf[SIZE] = { 0 };	//明文
	int clear_len = 0;	//明文长度

	unsigned char cipher_buf[SIZE] = { 0 };	//密文
	int cipher_len = 0;	//密文长度

	/*提示输入解密前后的两个文件*/

	//提示输入需要解密的文件
	printf("\nplease enter the file you want to decrypt: ");
	ret = scanf("%s", src_path);
	if (-1 == ret)
	{
		perror("\ndecryptFile: scanf error(src_path)");
		return;
	}

	//提示输入保存解密后结果的文件
	printf("\nplease enter the file you want to save the result: ");
	ret = scanf("%s", dst_path);
	if (-1 == ret)
	{
		perror("\ndecryptFile: scanf error(dst_path)");
		return;
	}

	//提示两个文件名不能一样
	ret = strcmp(src_path, dst_path);
	if (0 == ret)
	{
		printf("\nthe file name can no be the same");
		return;
	}

	/*打开文件*/

	//读(二进制)方式打开需要解密的文件
	src_fp = fopen(src_path, "rb");
	if (src_fp == NULL)
	{
		perror("\ndecryptFile: fopen error(src_path)");
		return;
	}

	//写(二进制)方式打开保存解密后结果的文件
	dst_fp = fopen(dst_path, "wb");
	if (dst_fp == NULL)
	{
		perror("\ndecryptFile: fopen error(dst_path)");
		//此时源文件已经打开,需要关闭
		goto CloseSrcFile;
		return;
	}

	/*解密文件*/
	/*
	1. 从源文件中读取数据
	2. =4k: DesDec_raw()
	3. <4k: DesDec()
	*/

	while (!feof(src_fp)) //文件没有结束
	{
		/*
		1. 从文件中读取内容
		2. cipher_buf: 存放文件内容的buf
		3. 1: 每次读1个字节
		4. SIZE: 一次读4k内存,读取内容的大小: SIZE * 1
		5. 返回值: 成功读取内容的块数
		*/
		cipher_len = fread(cipher_buf, 1, SIZE, src_fp);
		if (cipher_len < SIZE)	//如果读取内容<4k，跳出循环
		{
			break;
		}

		//size = 4k数据的解密处理
		//把密文cipher_buf(长度为cipher_len)解密为明文clear_buf(长度为clear_len)
		ret = DesDec_raw(cipher_buf, cipher_len, clear_buf, &clear_len);
		if (ret != 0)
		{
			printf("decryptFile: DesDec_raw error: %d\n", ret);
			//此时源文件,目的文件已经打开,需要关闭
			goto CloseSrcFile;
			goto CloseDstFile;
			return;
		}

		//把明文clear_buf(长度为clear_len)写到文件dst_fp中
		ret = fwrite(clear_buf, 1, clear_len, dst_fp);
		if (ret != clear_len)
		{
			printf("\nwrite to file failed(size = 4k)");
			//此时源文件,目的文件已经打开,需要关闭
			goto CloseSrcFile;
			goto CloseDstFile;
			return;
		}

	}

	//size < 4k的处理
	//把密文cipher_buf(长度为cipher_len)解密为明文clear_buf(长度为clear_len)
	ret = DesDec(cipher_buf, cipher_len, clear_buf, &clear_len);
	if (ret != 0)
	{
		printf("decryptFile: DesDec error: %d\n", ret);
		//此时源文件,目的文件已经打开,需要关闭
		goto CloseSrcFile;
		goto CloseDstFile;
		return;
	}

	//把明文clear_buf(长度为clear_len)写到文件dst_fp中
	ret = fwrite(clear_buf, 1, clear_len, dst_fp);
	if (ret != clear_len)
	{
		printf("\nwrite to file failed(size < 4k)");
		//此时源文件,目的文件已经打开,需要关闭
		goto CloseSrcFile;
		goto CloseDstFile;
		return;
	}

	/*关闭文件*/

CloseSrcFile:
	if (src_fp != NULL)
	{
		fclose(src_fp);
	}

CloseDstFile:
	if (dst_fp != NULL)
	{
		fclose(dst_fp);
	}
}

int main(void)
{
	int cmd = 0;	//用户输入的命令
	int ret = 0;	//函数返回值,检查调用函数是否出错

	while (1)
	{
		//输出提示菜单
		myMenu();

		printf("\nplease input a command: ");
		ret = scanf("%d", &cmd);
		if (-1 == ret)
		{
			perror("main: scanf error");
			return -1;
		}

		switch (cmd)
		{
		case 1:
			//加密文件
			encryptFile();
			break;
		case 2:
			//解密文件
			decryptFile();
			break;
		case 3:
			//清屏
			system("cls");
			break;
		default:
			//退出程序
			exit(0);
		}
	}

	printf("\n");
	system("pause");
	return 0;
}