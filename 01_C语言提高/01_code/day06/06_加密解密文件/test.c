#define _CRT_SECURE_NO_WARNINGS
#define SIZE (1024*4)

#include <stdio.h>	//printf(),perror(),scanf(),fopen(),fclose(),fread(),fwrite()
#include <stdlib.h>	//system()
#include <string.h>	//strlen(),memset()

#include "des.h"	//DesEnc(),DesDec(),DesEnc_raw(),DesDec_raw()

int main00(void)
{
	unsigned char clear[] = "deweh3g15h9gh301gy58";	//明文
	int clear_len = strlen(clear);	//明文长度

	unsigned char cipher[100] = { 0 };	//密文
	int cipher_len = 0;	//密文长度

	/*加密*/
	int re_DesEnc = DesEnc(clear, clear_len, cipher, &cipher_len);
	if (re_DesEnc != 0)
	{
		printf("mian: DesEnc error: %d\n", re_DesEnc);
		return re_DesEnc;
	}

	//输出
	printf("encryption:\n");
	printf("clear\t: %s\ncipher\t: %s\n", clear, cipher);

	/*解密*/
	memset(clear, 0, sizeof(clear));
	int dec_clear_len = 0;

	int re_DesDec = DesDec(cipher, cipher_len, clear, &dec_clear_len);
	if (re_DesDec != 0)
	{
		printf("mian: DesDec error: %d\n", re_DesDec);
		return re_DesDec;
	}

	if (dec_clear_len != clear_len)
	{
		printf("main: DesDec error: dec_clear_len != clear_len\n");
		return -1;
	}

	//输出
	printf("\ndecryption:\n");
	printf("clear\t: %s\n", clear);

	printf("\n");
	system("pause");
	return 0;
}

/*菜单*/
void menu(void)
{
	printf("\n************************************");
	printf("\n\t1. encrypt a file");
	printf("\n\t2. decrypt a file");
	printf("\n\t3. clear the screen");
	printf("\n\t4. exit");
	printf("\n************************************");
}

/*加密文件*/
void encrypt_file()
{
	/*
	1. 等于4K大小读文件	clear_buf
	1) clear_buf -> cipher_buf(通过加密的方式)
	2) cipher_buf -> 文件(将加密结果写入文件)
	*/

	/****************************************************************************/
	/*定义变量*/

	FILE* clear_fp = NULL;	//明文文件指针,需要加密的文件的文件指针
	FILE* cipher_fp = NULL;	//密文文件指针,保存加密后结果文件的文件指针

	char clear_path[512] = { 0 };	//明文文件路径,需要加密的文件路径
	char cipher_path[512] = { 0 };	//密文文件路径,保存加密后结果的文件路径

	unsigned char clear_buf[SIZE] = { 0 };	//4K,明文数组
	unsigned char cipher_buf[SIZE] = { 0 };	//4K,密文数组

	int clear_len = 0;	//明文长度
	int cipher_len = 0;	//密文长度

	int ret = 0;	//函数返回值(用来判断调用函数是否出错)

	/***************************************************************************/
	/*输出提示信息,提示用户输入文件*/

	printf("\nplease enter the file you want to encrypt: ");
	ret = scanf("%s", clear_path);
	if (ret == -1)
	{
		perror("encrypt_file: scanf clear_path error");
		return;
	}

	printf("\nplease enter the file you want to save the encrypted results: ");
	ret = scanf("%s", cipher_path);
	if (ret == -1)
	{
		perror("encrypt_file: scanf cipher_path error");
		return;
	}

	/********************************************************************/
	/*打开文件*/

	//以读(二进制)方式打开需要加密的文件clear_path
	clear_fp = fopen(clear_path, "rb");
	if (clear_fp == NULL)
	{
		perror("encrypt_file: fopen clear_path error");
		return;
	}

	//以写(二进制)方式打开保存加密后结果的文件cipher_path
	cipher_fp = fopen(cipher_path, "wb");
	if (cipher_fp == NULL)
	{
		perror("encrypt_file: fopen cipher_path error");
		goto CloseFile;
		return;
	}

	/***********************************************************************/
	/*读/写文件*/

	//循环读取文件
	while (1)
	{
		clear_len = fread(clear_buf, 1, SIZE, clear_fp);
		if (clear_len < SIZE)	//小于4K,跳出循环
		{
			break;
		}

		//1) clear_buf->cipher_buf(通过加密的方式)
		ret = DesEnc_raw(clear_buf, clear_len, cipher_buf, &cipher_len);
		if (ret != 0)
		{
			printf("encrypt_file: DesEnc_raw error: clear_len == 4K\n");
			goto CloseFile;
			return;
		}

		//2) cipher_buf -> 文件(将加密结果写入文件)
		ret = fwrite(cipher_buf, 1, cipher_len, cipher_fp);
		if (ret != cipher_len)
		{
			perror("encrypt_file: fwrite error(clear_len == 4K)");
			goto CloseFile;
			return;
		}
	}



	/*
	2. 小于4K大小读文件	clear_buf
	1) clear_buf -> cipher_buf(通过加密的方式)
	2) cipher_buf -> 文件(将加密结果写入文件)
	*/

	//先把ret置为0
	ret = 0;

	//1) clear_buf->cipher_buf(通过加密的方式)
	ret = DesEnc(clear_buf, clear_len, cipher_buf, &cipher_len);
	if (ret != 0)
	{
		printf("encrypt_file: DesEnc error: clear_len < 4K\n");
		goto CloseFile;
		return;
	}

	//2) cipher_buf -> 文件(将加密结果写入文件)
	ret = fwrite(cipher_buf, 1, cipher_len, cipher_fp);
	if (ret != cipher_len)
	{
		perror("encrypt_file: fwrite error(clear_len < 4K)");
		goto CloseFile;
		return;
	}

	/*******************************************************************/
	/*关闭文件*/
CloseFile:

	if (clear_fp != NULL)
	{
		fclose(clear_fp);
		clear_fp = NULL;
	}

	if (cipher_fp != NULL)
	{
		fclose(cipher_fp);
		cipher_fp = NULL;
	}
}

/*解密文件*/
void decrypt_file()
{

}

int main(int argc, char* argv[])
{
	int cmd = 0;
	while (1)
	{
		menu();
		printf("\nplease enter a command: ");
		int re_scanf = scanf("%d", &cmd);
		if (re_scanf == -1)
		{
			perror("main: scanf error");
			return -1;
		}

		switch (cmd)
		{
		case 1:
			encrypt_file();
			break;
		case 2:
			decrypt_file();
			break;
		case 3:
			system("cls");
			break;
		default:
			exit(0);
			break;
		}
	}

	printf("\n");
	system("pause");
	return 0;
}