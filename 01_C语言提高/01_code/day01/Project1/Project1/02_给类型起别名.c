#include <stdio.h>

typedef unsigned int u32;

//typedef�ͽṹ����ʹ��
struct MyStruct
{
	int a;
	int b;
};

typedef struct MyStruct2
{
	int a;
	int b;
}mystruct;

/*
void,������
1.��������Ϊ��,���庯��ʱ,������void����: int fun(void)
2.����û�з���ֵ: void fun(void)
3.���ܶ���void���͵���ͨ����: void a; //error,�޷�ȷ������,��ͬ���ͷ���ռ䲻һ��
4.���Զ���void*����: void* p; //ok,32λ��Զ4�ֽ�,64λ��Զ8�ֽ�
5.�������ͱ���: �̶��ڴ���С����
6.void* p����ָ��,��������ֵ,��������
*/

int main(void)
{
	u32 t;	//unsigned int

	//����ṹ�����,һ��Ҫ����struct�ؼ���
	struct MyStruct m1;
	//MyStruct m1;	//error
	mystruct m2;	//ok

	return 0;
}