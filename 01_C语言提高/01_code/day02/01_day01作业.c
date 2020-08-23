#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> //strcpy()
#include <stdlib.h> //system(),malloc(),free()

char* get_mem(int size)
{
    char* p2 = NULL;            //分配4个字节的内存 栈区也叫临时区
    p2 = (char*)malloc(size);

    return p2;
}

int main(void)
{
    char buf[100];
    int a = 10;     //分配4个字节的内存 栈区也叫临时区
    int* p;         //分配4个字节的内存
    p = &a;

    *p = 20;

    char* mp = get_mem(100);
    strcpy(mp, "ABCDEFG");

    if (mp != NULL)
    {
        printf("before free mp = %p\n", mp);
        free(mp);   //告诉系统,mp原来指向的内存可以被别人使用
        printf("after free mp = %p\n", mp);
        //释放完,mp就是野指针,但是还是保存着之前的地址,最好赋值为NULL;
        mp = NULL;
    }

    printf("\n");
    system("pause");
    return 0;
}