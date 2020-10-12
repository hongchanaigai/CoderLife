/*
4. ��������дһ�¼��ܽ��ܰ��������Ӳο���04_���ܽ����ļ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),scanf(),perror(),fopen(),fclose(),feof(),fread(),fwrite()
#include <stdlib.h>	//system()
#include <string.h>	//strcmp()

#include "des.h"	//DesEnc_raw(),DesEnc(),DesDec_raw(),DesDec()
#define SIZE 1024 * 4	//4K

/// <summary>
/// ��ʾ�˵�
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
/// �����ļ�
/// </summary>
void encryptFile()
{
	char src_path[512] = { 0 };	//Դ�ļ��ļ�·��
	char dst_path[512] = { 0 };	//Ŀ���ļ��ļ�·��
	int ret = 0;	//��������ֵ,�����ú����Ƿ����

	FILE* src_fp = NULL;	//Դ�ļ��ļ�ָ��
	FILE* dst_fp = NULL;	//Ŀ���ļ��ļ�ָ��

	unsigned char clear_buf[SIZE] = { 0 };	//����
	int clear_len = 0;	//���ĳ���

	unsigned char cipher_buf[SIZE] = { 0 };	//����
	int cipher_len = 0;	//���ĳ���

	/*��ʾ�������ǰ��������ļ�*/

	//��ʾ������Ҫ���ܵ��ļ�
	printf("\nplease enter the file you want to encrypt: ");
	ret = scanf("%s", src_path);
	if (-1 == ret)
	{
		perror("\nencryptFile: scanf error(src_path)");
		return;
	}

	//��ʾ���뱣����ܺ������ļ�
	printf("\nplease enter the file you want to save the result: ");
	ret = scanf("%s", dst_path);
	if (-1 == ret)
	{
		perror("\nencryptFile: scanf error(dst_path)");
		return;
	}

	//��ʾ�����ļ�������һ��
	ret = strcmp(src_path, dst_path);
	if (0 == ret)
	{
		printf("\nthe file name can no be the same");
		return;
	}

	/*���ļ�*/

	//��(������)��ʽ����Ҫ���ܵ��ļ�
	src_fp = fopen(src_path, "rb");
	if (src_fp == NULL)
	{
		perror("\nencryptFile: fopen error(src_path)");
		return;
	}

	//д(������)��ʽ�򿪱�����ܺ������ļ�
	dst_fp = fopen(dst_path, "wb");
	if (dst_fp == NULL)
	{
		perror("\nencryptFile: fopen error(dst_path)");
		//��ʱԴ�ļ��Ѿ���,��Ҫ�ر�
		goto CloseSrcFile;
		return;
	}

	/*�����ļ�*/
	/*
	1. ��Դ�ļ��ж�ȡ����
	2. 4k: DesEnc_raw()
	3. <4k: DesEnc()
	*/

	while (!feof(src_fp))	//�ļ�û�н���
	{
		/*
		1. ���ļ��ж�ȡ����
		2. clear_buf: ����ļ����ݵ�buf
		3. 1: ÿ�ζ�1���ֽ�
		4. SIZE: һ�ζ�4k���ڴ�,��ȡ���ݵĴ�С: SIZE * 1
		5. ����ֵ: �ɹ���ȡ���ݵĿ���
		*/
		clear_len = fread(clear_buf, 1, SIZE, src_fp);
		if (clear_len < SIZE)	//�����ȡ����<4k������ѭ��
		{
			break;
		}

		//size = 4k���ݵļ��ܴ���
		//������clear_buf(����Ϊclear_len)����Ϊ����cipher_buf(����Ϊcipher_len)
		ret = DesEnc_raw(clear_buf, clear_len, cipher_buf, &cipher_len);
		if (ret != 0)
		{
			printf("\nencryptFile: DesEnc_raw error: %d", ret);
			//��ʱԴ�ļ�,Ŀ���ļ��Ѿ���,��Ҫ�ر�
			goto CloseSrcFile;
			goto CloseDstFile;
			return;
		}

		//������cipher_buf(����Ϊcipher_len)д���ļ�dst_fp��
		ret = fwrite(cipher_buf, 1, cipher_len, dst_fp);
		if (ret != cipher_len)
		{
			printf("\nwrite to file failed(size == 4k)");
			//��ʱԴ�ļ�,Ŀ���ļ��Ѿ���,��Ҫ�ر�
			goto CloseSrcFile;
			goto CloseDstFile;
			return;
		}
	}

	//size < 4k�Ĵ���
	//������clear_buf(����Ϊclear_len)����Ϊ����cipher_buf(����Ϊcipher_len)
	ret = DesEnc(clear_buf, clear_len, cipher_buf, &cipher_len);
	if (ret != 0)
	{
		printf("encryptFile: DesEnc error: %d\n", ret);
		//��ʱԴ�ļ�,Ŀ���ļ��Ѿ���,��Ҫ�ر�
		goto CloseSrcFile;
		goto CloseDstFile;
		return;
	}

	//������cipher_buf(����Ϊcipher_len)д���ļ�wFp��
	ret = fwrite(cipher_buf, 1, cipher_len, dst_fp);
	if (ret != cipher_len)
	{
		printf("\nwrite to file failed(size < 4k)");
		//��ʱԴ�ļ�,Ŀ���ļ��Ѿ���,��Ҫ�ر�
		goto CloseSrcFile;
		goto CloseDstFile;
		return;
	}

	/*�ر��ļ�*/

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
/// �����ļ�
/// </summary>
void decryptFile()
{
	char src_path[512] = { 0 };	//Դ�ļ��ļ�·��
	char dst_path[512] = { 0 };	//Ŀ���ļ��ļ�·��
	int ret = 0;	//��������ֵ,�����ú����Ƿ����

	FILE* src_fp = NULL;	//Դ�ļ��ļ�ָ��
	FILE* dst_fp = NULL;	//Ŀ���ļ��ļ�ָ��

	unsigned char clear_buf[SIZE] = { 0 };	//����
	int clear_len = 0;	//���ĳ���

	unsigned char cipher_buf[SIZE] = { 0 };	//����
	int cipher_len = 0;	//���ĳ���

	/*��ʾ�������ǰ��������ļ�*/

	//��ʾ������Ҫ���ܵ��ļ�
	printf("\nplease enter the file you want to decrypt: ");
	ret = scanf("%s", src_path);
	if (-1 == ret)
	{
		perror("\ndecryptFile: scanf error(src_path)");
		return;
	}

	//��ʾ���뱣����ܺ������ļ�
	printf("\nplease enter the file you want to save the result: ");
	ret = scanf("%s", dst_path);
	if (-1 == ret)
	{
		perror("\ndecryptFile: scanf error(dst_path)");
		return;
	}

	//��ʾ�����ļ�������һ��
	ret = strcmp(src_path, dst_path);
	if (0 == ret)
	{
		printf("\nthe file name can no be the same");
		return;
	}

	/*���ļ�*/

	//��(������)��ʽ����Ҫ���ܵ��ļ�
	src_fp = fopen(src_path, "rb");
	if (src_fp == NULL)
	{
		perror("\ndecryptFile: fopen error(src_path)");
		return;
	}

	//д(������)��ʽ�򿪱�����ܺ������ļ�
	dst_fp = fopen(dst_path, "wb");
	if (dst_fp == NULL)
	{
		perror("\ndecryptFile: fopen error(dst_path)");
		//��ʱԴ�ļ��Ѿ���,��Ҫ�ر�
		goto CloseSrcFile;
		return;
	}

	/*�����ļ�*/
	/*
	1. ��Դ�ļ��ж�ȡ����
	2. =4k: DesDec_raw()
	3. <4k: DesDec()
	*/

	while (!feof(src_fp)) //�ļ�û�н���
	{
		/*
		1. ���ļ��ж�ȡ����
		2. cipher_buf: ����ļ����ݵ�buf
		3. 1: ÿ�ζ�1���ֽ�
		4. SIZE: һ�ζ�4k�ڴ�,��ȡ���ݵĴ�С: SIZE * 1
		5. ����ֵ: �ɹ���ȡ���ݵĿ���
		*/
		cipher_len = fread(cipher_buf, 1, SIZE, src_fp);
		if (cipher_len < SIZE)	//�����ȡ����<4k������ѭ��
		{
			break;
		}

		//size = 4k���ݵĽ��ܴ���
		//������cipher_buf(����Ϊcipher_len)����Ϊ����clear_buf(����Ϊclear_len)
		ret = DesDec_raw(cipher_buf, cipher_len, clear_buf, &clear_len);
		if (ret != 0)
		{
			printf("decryptFile: DesDec_raw error: %d\n", ret);
			//��ʱԴ�ļ�,Ŀ���ļ��Ѿ���,��Ҫ�ر�
			goto CloseSrcFile;
			goto CloseDstFile;
			return;
		}

		//������clear_buf(����Ϊclear_len)д���ļ�dst_fp��
		ret = fwrite(clear_buf, 1, clear_len, dst_fp);
		if (ret != clear_len)
		{
			printf("\nwrite to file failed(size = 4k)");
			//��ʱԴ�ļ�,Ŀ���ļ��Ѿ���,��Ҫ�ر�
			goto CloseSrcFile;
			goto CloseDstFile;
			return;
		}

	}

	//size < 4k�Ĵ���
	//������cipher_buf(����Ϊcipher_len)����Ϊ����clear_buf(����Ϊclear_len)
	ret = DesDec(cipher_buf, cipher_len, clear_buf, &clear_len);
	if (ret != 0)
	{
		printf("decryptFile: DesDec error: %d\n", ret);
		//��ʱԴ�ļ�,Ŀ���ļ��Ѿ���,��Ҫ�ر�
		goto CloseSrcFile;
		goto CloseDstFile;
		return;
	}

	//������clear_buf(����Ϊclear_len)д���ļ�dst_fp��
	ret = fwrite(clear_buf, 1, clear_len, dst_fp);
	if (ret != clear_len)
	{
		printf("\nwrite to file failed(size < 4k)");
		//��ʱԴ�ļ�,Ŀ���ļ��Ѿ���,��Ҫ�ر�
		goto CloseSrcFile;
		goto CloseDstFile;
		return;
	}

	/*�ر��ļ�*/

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
	int cmd = 0;	//�û����������
	int ret = 0;	//��������ֵ,�����ú����Ƿ����

	while (1)
	{
		//�����ʾ�˵�
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
			//�����ļ�
			encryptFile();
			break;
		case 2:
			//�����ļ�
			decryptFile();
			break;
		case 3:
			//����
			system("cls");
			break;
		default:
			//�˳�����
			exit(0);
		}
	}

	printf("\n");
	system("pause");
	return 0;
}