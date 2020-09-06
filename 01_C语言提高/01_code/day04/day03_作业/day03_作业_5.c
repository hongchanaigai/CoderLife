/*
5. ���ַ�����������������abcd11111abcd2222abcdqqqqq����,��дһ�������ӿڣ�������½����
	���ַ����滻�ɣ�dcba11111dcba2222dcbaqqqqq�������ѽ��������
	Ҫ��
		1. ��ȷʵ�ֽӿں͹���
		2. ��д��������
	src:    ԭ�ַ���
	dst:    ���ɵĻ���Ҫ�����ַ���
	sub:    ��Ҫ���ҵ����ַ���
	new_sub:�ỻ�������ַ���
	return : 0 �ɹ�
			-1 ʧ��
int replaceSubstr(char* src, char** dst, char* sub,  char* new_sub)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system(),malloc(),free()
#include <string.h>	//strstr(),strncat(),strlen(),strcat(),strcpy()

/*
* ����: �滻�ַ���
* ����: src	ԭ�ַ���
		dst	���ɵĻ���Ҫ�����ַ���
		sub	��Ҫ���ҵ����ַ���
		new_sub	�ỻ�������ַ���
* ����ֵ: 0	�ɹ�
		 ��0 ʧ��
*/
int replaceSubstr(char* src/*in*/, char** dst/*out*/, char* sub/*in*/, char* new_sub/*in*/)
{
	// src = "0000abcd11111abcd2222abcdqqqqq"
	// dst = "0000dcba11111dcba2222dcbaqqqqq"
	// sub = "abcd"
	// new_sub = "dcba"
	
	if (src == NULL || dst == NULL || sub == NULL || new_sub == NULL)
	{//�����ж�
		printf("replaceSubstr: src/dst/sub/new_sub == NULL\n");
		return -1;
	}

	char tmp[512] = { 0 }; //��ʱ����, �ַ�����
	char* start = src; //��¼���ҵ����
	char* p = NULL;	//ƥ���ַ������׵�ַ
	
	do
	{
		// src = "0000abcd11111abcd2222abcdqqqqq"
		// dst = "0000dcba11111dcba2222dcbaqqqqq"
		// sub = "abcd"
		// new_sub = "dcba"
		p = strstr(start, sub);	
		if (p != NULL)
		{
			int len = p - start;	//��ƥ��ĳ���,��Ҫ��������ʱ�ַ�����
			//len = 4,p = src[4],start = src[0]
			if (len > 0)
			{
				//��ƥ���ַ���ǰ����������ӹ�ȥ
				strncat(tmp, start, len);
				//tmp = "0000",start = str[0],len = 4
			}

			strncat(tmp, new_sub, strlen(new_sub)); //׷���滻���´�
			//tmp = "0000dcba",strlen(new_sub) = strlen("dcab") = 4

			//���Ĳ��ҵ����λ��
			start = p + strlen(sub);
			//start = str[8],p = str[4],strlen(sub) = strlen("abcd") = 4
		}
		else
		{//û�ҵ�
			strcat(tmp, start);	//��ԭʼ�ַ�������,����
			break;
		}
	} while (*start != '\0');	//�ȼ���start[i] != 0

	//��ʱ����buf
	char* buf = (char*)malloc(strlen(tmp) + 1);
	strcpy(buf, tmp);
	*dst = buf;	//��Ӹ�ֵ��ָ����ڵ�����

	return 0;
}

void free_dst(char* dst)
{
		free(dst);
		dst = NULL;
}

void free_dst2(char** dst)
{
	char* tmp_dst = *dst;
	if(tmp_dst != NULL)
	{
		free(tmp_dst);
	}
	
	*dst = NULL;
}

int main(void)
{
	char* src = "0000abcd11111abcd2222abcdqqqqq";	//	ԭʼ�ַ���
	char* dst = NULL;	//��replaceSubstr�����з���ռ�

	int ret = 0;	//������
	ret = replaceSubstr(src/*in*/, &dst/*out*/, "abcd"/*in*/, "dcba"/*in*/);
	
	if (ret != 0)
	{//replaceSubstr��������,��ӡ������Ϣ
		printf("main: replaceSubstr error: %d\n", ret);
		system("pause");	//��ͣ��Ļ
		return ret;
	}

	printf("src = [%s]\n", src);	//ԭʼ�ַ���
	printf("dst = [%s]\n", dst);	//�滻���ַ���

#if 0
	if (dst != NULL)
	{//�ͷ��ڴ�
		free(dst);
		dst = NULL;
	}
#endif	//0

#if 0
	//�ͷ��ڴ�
	free_dst(dst);
	dst = NULL;
#endif	//0
	
	//�ͷ��ڴ�
	free_dst2(&dst);

	printf("\n");
	system("pause");
	return 0;
}