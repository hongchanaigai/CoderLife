/*
8. 将字符串数组进行排序

int sort(char **array1, int num1,
         char (*array2)[30], int num2,
         char ***myp3, int* num3);

         int  main()
         {
             int ret = 0;
             char* p1[] = { "aa", "ccccccc", "bbbbbb" };
             char buf2[10][30] = { "111111", "3333333", "222222" };
             char** p3 = NULL;
             int len1, len2, len3, i = 0;

             len1 = sizeof(p1) / sizeof(*p1);
             len2 = 3;

             ret = sort(p1, len1, buf2, len2, &p3, &len3);

             return 0;
         }
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system(), malloc(), free()
#include <string.h> //strcmp(), strlen(), strcpy()

/// <summary>
/// 将字符串数组进行排序
/// </summary>
/// <param name="array1">指针数组首地址char* p1[] = { "aa", "ccccccc", "bbbbbb" };</param>
/// <param name="num1">指针数组元素个数char buf2[10][30] = { "111111", "3333333", "222222" };</param>
/// <param name="array2">二维数组首元素地址</param>
/// <param name="num2">二维数组行数</param>
/// <param name="myp3">二级指针的地址,保存p1和buf2的字符串char** p3 = NULL;</param>
/// <param name="num3">p3的字符串个数</param>
/// <returns>成功返回0,不成功返回非0</returns>
int sort(char** array1, int num1, char(*array2)[30], int num2, char*** myp3/*out*/, int* num3)
{
    if (array1 == NULL || array2 == NULL || myp3 == NULL || num3 == NULL)
    {
        printf("sort: input error: array1 == NULL || array2 == NULL || myp3 == NULL || num3 == NULL\n");
        return -1;
    }

    //给myp3动态分配空间

    //打造一个指针数组char* tmp[num1 + num2]
    char** tmp = (char**)malloc(sizeof(char*) * (num1 + num2));
    if (tmp == NULL)
    {
        printf("sort: malloc error: tmp == NULL");
        return -2;
    }

    //给每个指针分配内存,指向堆区
    for (int i = 0; i < num1; ++i)
    {//array1的内容传给tmp
        //tmp[i] = (char*)malloc(sizeof(char) * (strlen(array1[i]) + 1));
        tmp[i] = (char*)malloc(sizeof(char) * 50);
        if(tmp[i] != NULL)
		{
			strcpy(tmp[i], array1[i]);
		}
    }

    for (int i = num1, j = 0; i < num1 + num2; ++i, ++j)
    {//array2的内容传给tmp
        //tmp[i] = (char*)malloc(sizeof(char) * (strlen(array2[j]) + 1));
        tmp[i] = (char*)malloc(sizeof(char) * 50);
        if(tmp[i] != NULL)
		{
			strcpy(tmp[i], array2[j]);
		}
    }

    //排序,选择法
    //char* p = NULL;
    char p[50] = { 0 };
    for (int i = 0; i < num1 + num2 - 1; ++i)
    {
        for (int j = i + 1; j < num1 + num2; ++j)
        {
            if (strcmp(tmp[i], tmp[j]) > 0)
            {//升序,交换指针指向
                //p = tmp[i];
                //tmp[i] = tmp[j];
                //tmp[j] = p;
                strcpy(p, tmp[i]);
                strcpy(tmp[i], tmp[j]);
                strcpy(tmp[j], p);
            }
        }
    }
	
	//间接赋值是指针存在最大意义
    *myp3 = tmp;
    *num3 = num1 + num2;
    
    return 0;
}

/// <summary>
/// 释放p3所指向的内存
/// </summary>
/// <param name="p3">二级指针的地址,保存p1和buf2的字符串char** p3 = NULL;</param>
void free_buf(char*** p3, int len3)
{
    if (p3 == NULL)
    {
        printf("free_buf: input error: p3 == NULL\n");
        return;
    }

    char** tmp = *p3;
    for (int i = 0; i < len3; ++i)
    {
        if (tmp[i] != NULL)
        {
            free(tmp[i]);
            tmp[i] = NULL;
        }
    }

    if (tmp != NULL)
    {
        free(tmp);
        *p3 = NULL;
    }
}

int main(void)
{
    int ret = 0;
    char* p1[] = { "aa", "ccccccc", "bbbbbb" }; //指针数组
    char buf2[10][30] = { "111111", "3333333", "222222" };  //二维数组
    char** p3 = NULL;   //动态打造
    int len1, len2, len3, i = 0;

    len1 = sizeof(p1) / sizeof(*p1);
    len2 = 3;
    len3 = 0;

    ret = sort(p1, len1, buf2, len2, &p3, &len3);
    if (ret != 0)
    {
        printf("main: sort error: %d\n", ret);
        return ret;
    }

    //输出结果
    printf("p1: ");
    for (i = 0; i < len1; ++i)
    {
        printf("%s ", p1[i]);
    }

    printf("\nbuf2: ");
    for (i = 0; i < len2; ++i)
    {
        printf("%s ", buf2[i]);
    }

    printf("\np3: ");
    for (i = 0; i < len3; ++i)
    {
        printf("%s ", p3[i]);
    }
    
    //释放p3所指向的内存
    //在函数内部把p3赋值为NULL
    free_buf(&p3, len3);

    printf("\n");
    system("pause");
    return 0;
}