#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),fopen(),fputs(),fclose(),fflush()
#include <stdlib.h>	//system()
#include <string.h>

int main(void)
{
	/*
	�����ļ�,���Ȱ����ݷŵ�������,�������/�ļ��ر�/ˢ�»�����,�Ż������д���ļ�
	���ǻ���������,�Ż�д��
	*/
	char buf[] = "this is a 00_test.\n";
	
	//���ļ�
	FILE* fp = fopen("./00_test.txt", "w+");
	//д�ļ�
	fputs(buf, fp);
	//ˢ�»�����
	fflush(fp);
	//�ر��ļ�
	fclose(fp);

	printf("\n");
	system("pause");
	return 0;
}