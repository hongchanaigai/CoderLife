#define _CRT_SECURE_NO_WARNINGS
#define SIZE (1024*4)

#include <stdio.h>	//printf(),perror(),scanf(),fopen(),fclose(),fread(),fwrite()
#include <stdlib.h>	//system()
#include <string.h>	//strlen(),memset()

#include "des.h"	//DesEnc(),DesDec(),DesEnc_raw(),DesDec_raw()

int main00(void)
{
	unsigned char clear[] = "deweh3g15h9gh301gy58";	//����
	int clear_len = strlen(clear);	//���ĳ���

	unsigned char cipher[100] = { 0 };	//����
	int cipher_len = 0;	//���ĳ���

	/*����*/
	int re_DesEnc = DesEnc(clear, clear_len, cipher, &cipher_len);
	if (re_DesEnc != 0)
	{
		printf("mian: DesEnc error: %d\n", re_DesEnc);
		return re_DesEnc;
	}

	//���
	printf("encryption:\n");
	printf("clear\t: %s\ncipher\t: %s\n", clear, cipher);

	/*����*/
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

	//���
	printf("\ndecryption:\n");
	printf("clear\t: %s\n", clear);

	printf("\n");
	system("pause");
	return 0;
}

/*�˵�*/
void menu(void)
{
	printf("\n************************************");
	printf("\n\t1. encrypt a file");
	printf("\n\t2. decrypt a file");
	printf("\n\t3. clear the screen");
	printf("\n\t4. exit");
	printf("\n************************************");
}

/*�����ļ�*/
void encrypt_file()
{
	/*
	1. ����4K��С���ļ�	clear_buf
	1) clear_buf -> cipher_buf(ͨ�����ܵķ�ʽ)
	2) cipher_buf -> �ļ�(�����ܽ��д���ļ�)
	*/

	/****************************************************************************/
	/*�������*/

	FILE* clear_fp = NULL;	//�����ļ�ָ��,��Ҫ���ܵ��ļ����ļ�ָ��
	FILE* cipher_fp = NULL;	//�����ļ�ָ��,������ܺ����ļ����ļ�ָ��

	char clear_path[512] = { 0 };	//�����ļ�·��,��Ҫ���ܵ��ļ�·��
	char cipher_path[512] = { 0 };	//�����ļ�·��,������ܺ������ļ�·��

	unsigned char clear_buf[SIZE] = { 0 };	//4K,��������
	unsigned char cipher_buf[SIZE] = { 0 };	//4K,��������

	int clear_len = 0;	//���ĳ���
	int cipher_len = 0;	//���ĳ���

	int ret = 0;	//��������ֵ(�����жϵ��ú����Ƿ����)

	/***************************************************************************/
	/*�����ʾ��Ϣ,��ʾ�û������ļ�*/

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
	/*���ļ�*/

	//�Զ�(������)��ʽ����Ҫ���ܵ��ļ�clear_path
	clear_fp = fopen(clear_path, "rb");
	if (clear_fp == NULL)
	{
		perror("encrypt_file: fopen clear_path error");
		return;
	}

	//��д(������)��ʽ�򿪱�����ܺ������ļ�cipher_path
	cipher_fp = fopen(cipher_path, "wb");
	if (cipher_fp == NULL)
	{
		perror("encrypt_file: fopen cipher_path error");
		goto CloseFile;
		return;
	}

	/***********************************************************************/
	/*��/д�ļ�*/

	//ѭ����ȡ�ļ�
	while (1)
	{
		clear_len = fread(clear_buf, 1, SIZE, clear_fp);
		if (clear_len < SIZE)	//С��4K,����ѭ��
		{
			break;
		}

		//1) clear_buf->cipher_buf(ͨ�����ܵķ�ʽ)
		ret = DesEnc_raw(clear_buf, clear_len, cipher_buf, &cipher_len);
		if (ret != 0)
		{
			printf("encrypt_file: DesEnc_raw error: clear_len == 4K\n");
			goto CloseFile;
			return;
		}

		//2) cipher_buf -> �ļ�(�����ܽ��д���ļ�)
		ret = fwrite(cipher_buf, 1, cipher_len, cipher_fp);
		if (ret != cipher_len)
		{
			perror("encrypt_file: fwrite error(clear_len == 4K)");
			goto CloseFile;
			return;
		}
	}



	/*
	2. С��4K��С���ļ�	clear_buf
	1) clear_buf -> cipher_buf(ͨ�����ܵķ�ʽ)
	2) cipher_buf -> �ļ�(�����ܽ��д���ļ�)
	*/

	//�Ȱ�ret��Ϊ0
	ret = 0;

	//1) clear_buf->cipher_buf(ͨ�����ܵķ�ʽ)
	ret = DesEnc(clear_buf, clear_len, cipher_buf, &cipher_len);
	if (ret != 0)
	{
		printf("encrypt_file: DesEnc error: clear_len < 4K\n");
		goto CloseFile;
		return;
	}

	//2) cipher_buf -> �ļ�(�����ܽ��д���ļ�)
	ret = fwrite(cipher_buf, 1, cipher_len, cipher_fp);
	if (ret != cipher_len)
	{
		perror("encrypt_file: fwrite error(clear_len < 4K)");
		goto CloseFile;
		return;
	}

	/*******************************************************************/
	/*�ر��ļ�*/
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

/*�����ļ�*/
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