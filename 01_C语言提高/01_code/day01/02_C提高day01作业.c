1. �������͵ı�����ʲô�� ���ӱ������ĽǶȿ��ǣ�
	//�̶��ڴ���С�ı���

2. ���Ϊһ�����������������
	//typedef ���������� ����

3. ��Ȼ��ջ�ռ䣬Ϊ��Ҫ�жѿռ䣿
	//ջ�ռ���ִ����֮����ͷ�,��ʱ����Ҫ,���Բ����ѿռ�
	ջ�Ŀռ���˭����ͻ��գ�
	//ϵͳ�Զ�����ͻ���
	�ѵĿռ�����˭����ͻ��գ�
	//�ֶ�����ͻ���(����: malloc/new	����: free/delete)

4. ��һ����������������������
	void print_array(int a[128])
	{
		//sizeof(a) = ?
		//4
	}
	
5. ��һ�����飬������Ԫ�ظ�����
	int main(void)
	{
		int a[] = {1, 5, 7, 0, 10, 7, 3};
		//int n = sizeof(a) / sizeof(a[0]);
		
	}
	
	
6. ��32λƽ̨��
	char ************p = NULL;
	int *q = NULL;
	sizeof(p) = ?
	//4
	sizeof(q) = ?
	//4


7. �������������ڴ�����ͼ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_mem(int size)
{
    char *p2 = NULL;            //����4���ֽڵ��ڴ� ջ��Ҳ����ʱ��
    p2 = (char *)malloc(size);

    return p2;
}

int main(void)
{
    char buf[100];
    int a = 10;     //����4���ֽڵ��ڴ� ջ��Ҳ����ʱ��
    int *p;         //����4���ֽڵ��ڴ�
    p = &a;   

    *p = 20;

    char *mp = get_mem(100);
    strcpy(mp, "ABCDEFG");

    if (mp != NULL)
    {
        free(mp);
		mp = NULL;
    }

    return 0;
}
