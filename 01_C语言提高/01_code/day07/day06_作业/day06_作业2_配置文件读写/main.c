/*
2. ʵ�������ļ���д��д���ܣ�key=value��ʽ����ִ�г���ο���02_�����ļ���
	��ʾ��
	a) ѭ����ÿһ��, ������а���key�����key��value�޸�
	b) ��������ж�������key�������ļ���β׷�ӣ� "key = value"
	c) �ļ���С���ܳ���8k
	c) �ο���fgets(), strstr(), sprintf(), strcat(), fprintf(), fputs(), fseek(),  ftell(),  rewind()
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),scanf()
#include <stdlib.h>	//system()
#include <string.h>	//strlen()
#include "mycfg.h"	//writeCfgFile(),readCfgFile()

#define CFG_FILENAME "./mycfg.ini"	//�����ļ��ļ���

void myMenu()
{
	printf("\n***********************************");
	printf("\n\t1 write a profile");
	printf("\n\t2 read  a profile");
	printf("\n\t3 clear the screen");
	printf("\n\t4 exit");
	printf("\n***********************************");
}

void myWrite()
{
	int ret = 0;
	char key[512] = { 0 };
	char value[512] = { 0 };

	printf("\nplease input a key: ");
	ret = scanf("%s", key);
	if (ret == -1)
	{
		perror("myWrite: scanf error(key)");
		return;
	}

	printf("\nplease input a value: ");
	ret = scanf("%s", value);
	if (ret == -1)
	{
		perror("myWrite: scanf error(value)");
		return;
	}

	ret = writeCfgFile(CFG_FILENAME, key, value, strlen(value));
	if (ret != 0) //ʧ��
	{
		printf("myWrite: writeCfgFile error: %d\n", ret);
		return;
	}

	printf("\nwhat is written��%s = %s\n\n", key, value);

}

void myRead()
{
	int ret = 0;
	char key[512] = { 0 };
	char value[512] = { 0 };
	int len = 0;

	printf("\nplease input a key: ");
	ret = scanf("%s", key);
	if (ret == -1)
	{
		perror("myRead: scanf error(key)");
		return;
	}

	ret = readCfgFile(CFG_FILENAME, key, value, &len);
	if (ret != 0) //ʧ��
	{
		printf("myRead: readCfgFile error: %d\n", ret);
		return;
	}

	printf("\n the key is: %s, the value is: %s, the lenth is %d\n", key, value, len);
}

int main(void)
{
	int cmd = 0;
	int ret = 0;

	while (1)
	{
		myMenu();
		printf("\nplease input a command: ");
		ret = scanf("%d", &cmd);
		if (ret == -1)
		{
			perror("main: scanf error");
			return -1;
		}

		switch (cmd)
		{
		case 1:
			myWrite();
			break;
		case 2:
			myRead();
			break;
		case 3:
			system("cls");
			break;
		default:
			exit(0);
		}

	}

	printf("\n");
	system("pause");
	return 0;
}