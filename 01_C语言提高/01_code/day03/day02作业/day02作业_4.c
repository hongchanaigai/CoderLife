/*
4. ��ֵ�ԣ���key = value�����ַ������ڿ����о���ʹ��
	Ҫ��1�����Լ�����һ���ӿڣ�ʵ�ָ���key��ȡ.
	Ҫ��2����д����������
	Ҫ��3����ֵ���м������n��ո���ȥ���ո�

	ע�⣺��ֵ���ַ�����ʽ�������£�
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
* ����: ��ȡ�ǿ��ַ���
* ����: inbufԭʼ�ַ����׵�ַ
*		outbuf�ǿ��ַ����׵�ַ
* ����ֵ: 0�ɹ�,��0ʧ��
*/
int trimSpace(char* inbuf, char* outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		printf("trimSpace: input error\n");
		return -1;
	}

	char* tmp_inbuf = inbuf;	//��������,��ֱ��ʹ���β�
	int begin = 0;	//�ַ�����Ԫ���±�
	int end = strlen(tmp_inbuf) - 1;	//�ַ���βԪ���±�
	if (end < 0)
	{
		printf("trimSpace: end < 0\n");
		return -2;
	}

	//����Ԫ�ؿ�ʼ������
	while (isspace(tmp_inbuf[begin]) && tmp_inbuf[begin] != '\0')
	{
		begin++;
	}

	//��βԪ�ؿ�ʼ������
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
* ����: ����keyֵ��ȡ��Ӧ��valueֵ
* ����: keyvaluebuf,��ֵ�ԣ���key = value�����ַ����׵�ַ
*		keybuf,keyֵ�ַ����׵�ַ
*		valuebuf,valueֵ�ַ����׵�ַ
*		valuebuflen,valueֵ�ַ�������
* ����ֵ: 0�ɹ�,��0ʧ��
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

	//����ƥ���keybuf
	//"key1 =   value1"��"key1",�ҵ������׵�ַ
	char* p = NULL;
	p = strstr(tmp_keykeyvaluebuf, tmp_keybuf);
	if (p == NULL)
	{//û�ҵ�ƥ���keybuf,��û�ҵ�"key1"
		printf("getKeyByValue: can not find keybuf\n");
		return -2;
	}
	//����ҵ�,�����������λ��,����keybuf,������"key1"
	//p = " =   value1"
	//"key1 =   value1" --> " =   value1"
	p += strlen(tmp_keybuf);

	//����"="
	p = strstr(p, "=");
	if (p == NULL)
	{//û�ҵ�"="
		printf("getKeyByValue: can not find =\n");
		return -3;
	}
	//�ҵ�"=",����"="
	//p = "   value1"
	//" =   value1" --> "   value1"
	p += strlen("=");

	//ȡ�ǿ��ַ���,��valuebuf
	int ret = 0;
	ret = trimSpace(p, valuebuf);
	if (ret != 0)
	{
		printf("getKeyByValue: trimSpace error: %d\n", ret);
		return ret;
	}

	//��ȡvaluebuf�ĳ���
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

#if 0	//��������
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
#endif	//�����������

	printf("\n");
	system("pause");
	return 0;
}