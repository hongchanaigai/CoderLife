#include <stdio.h>
#include <stdlib.h>	//system()

int main00(void)
{
	char src[] = "shafoipjeokcpkvqepgk";
	char dst[100] = { 0 };

	int i = 0;
	for (i = 0; src[i] != '\0'; ++i)
	{
		dst[i] = src[i];
	}
	//��������
	dst[i] = '\0';

	printf("src = %s\n", src);
	printf("dst = %s\n", dst);

	printf("\n");
	system("pause");
	return 0;
}

void my_strcpy(char* dst, char* src)
{
	int i = 0;
	for (i = 0; src[i] != '\0'; ++i)
	{
		dst[i] = src[i];
	}
	//��������
	dst[i] = '\0';
}

void my_strcpy2(char* dst, char* src)
{
	while (*src != '\0')
	{
		*dst = *src;
		dst++; src++;
	}
	*dst = '\0';
}

void my_strcpy3(char* dst, char* src)
{
	while (*src != '\0')
	{
		*dst++ = *src++;	//�������ټ�
	}
	*dst = '\0';
}

void my_strcpy4(char* dst, char* src)
{
	//*dst = *src;
	//*dst++; *src++;
	//�ж�*dst�Ƿ�Ϊ0,Ϊ0����ѭ��
	while (*dst++ = *src++);
}

//�ɹ�Ϊ0,ʧ�ܷ�0
//1. �ж��β�ָ���Ƿ�ΪNULL
//2. ��ò�Ҫֱ��ʹ���β�
int my_strcpy5(char* dst, char* src)
{
	if (dst == NULL || src == NULL)
	{
		return -1;
	}
	
	//��������,���βνӹ���
	char* to = dst;
	char* from = src;

	//*to = *from;
	//*to++; *from++;
	//�ж�*to�Ƿ�Ϊ0,Ϊ0����ѭ��
	while (*to++ = *from++);

	printf("my_strcpy5: dst = %s\n", dst);

	return 0;
}

int main(void)
{
	char src[] = "shafoipjeokcpkvqepgk";
	char dst[100] = { 0 };

	//my_strcpy(dst, src);
	//my_strcpy2(dst, src);
	//my_strcpy3(dst, src);
	//my_strcpy4(dst, src);

	int ret = 0;
	ret = my_strcpy5(dst, src);
	if (ret != 0)
	{
		printf("my_strcpy5 error: %d\n", ret);
		return ret;
	}

	printf("src = %s\n", src);
	printf("dst = %s\n", dst);

	printf("\n");
	system("pause");
	return 0;
}