#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf(),fputc(),fgets(),fprintf(),fopen(),perror(),fclose(),feof()
#include <stdlib.h>	//system()
#include <string.h>	//strlen()

int main00(void)
{
	fputc('a', stdout);	//stdout -> ��Ļ,��ӡ��ͨ��Ϣ

	char ch;
	ch = fgetc(stdin);	//stdin -> ����
	printf("ch = %c\n", ch);

	fprintf(stderr, "%c", ch);	//stderr -> ��Ļ,��ӡ������Ϣ
	fputc(ch, stderr);

	printf("\n");
	system("pause");
	return 0;
}


int main01(int argc, char* argv[])
{
	FILE* fp = NULL;

	//���ļ�

	//���������ȼ�
	//D:\\CoderLife\\Project1\\Project1\\01.txt		windows��д��
	//D:/CoderLife/Project1/Project1/01.txt			windows,linux��֧��,����д"/"

	//����·��,D:\\CoderLife\\Project1\\Project1\\01.txt
	//���·��,/,45��,./,../(����),linux,windows

	//vs:�������ʱ,�������Ŀ����
	//ֱ�����п�ִ�г���,����ڳ���

	//���ַ�������д,ûд��ʹ��"\"����,"1234567890"\
		"hfqieugherghoqehgio"
	char* p = "2164964103572035720"\
		"cbisvbeorgheogjpwkdcpwe";
	printf("p = %s\n", p);

	fp = fopen("./01.txt", "w+");
	//fp = fopen("./01.txt", "r+");
	if (fp == NULL)
	{
		perror("main: fopen");
		system("pause");
		return -1;
	}

	//�ر��ļ�
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	printf("\n");
	system("pause");
	return 0;
}


void my_fputc(char* path)
{
	FILE* fp = NULL;

	/*���ļ�*/
	//"w+": д����ʽ��,�ļ�������,�򴴽�;�ļ�����,���������д
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		//perror��������: �ַ���
		perror("my_fputc: fopen");
		return;
	}

	/*д�ļ�*/
	char* buf = "this is a test for fputc";
	int n = strlen(buf);

	for (int i = 0; i < n; ++i)
	{
		//����ֵ: �ɹ�����д����ַ�,ʧ�ܷ���EOF
		int re_fputc = fputc(buf[i], fp);
		printf("re_fputc = %c\n", re_fputc);
	}

	/*�ر��ļ�*/
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fgetc(char* path)
{
	FILE* fp = NULL;

	/*���ļ�*/
	//"r+": ��д��ʽ��,�ļ�������,��ʧ��
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_getc: fopen");
		return;
	}

	/*���ļ�*/
	char ch = 0;

#if 0
	while ((ch = fgetc(fp)) != EOF)
	{
		printf("%c", ch);
	}
	printf("\n");
#endif // 0

	while (!feof(fp))	//�ļ�û�н���
	{
		ch = fgetc(fp);
		printf("%c", ch);
	}
	printf("\n");

	/*�ر��ļ�*/
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main(int argc, char* argv[])
{
	my_fputc("../01.txt");	//д�ļ�
	my_fgetc("../01.txt");	//���ļ�

	printf("\n");
	system("pause");
	return 0;
}