/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-02 17:18
 * Last modified  : 2020-08-02 17:18
 * Filename       : 01_作业2_get_sum.c
 * Description    : 实现get_sum()函数 
 * *******************************************************/
#include <stdio.h> //sscanf()
#include <stdlib.h> //atoi()
#include <string.h> //strcpy(),strtok()

int get_sum(char *str)
{
	char tmp[100] = {0}; //初始化为0
	strcpy(tmp, str); //把str字符串拷贝到tmp字符串

	//切割
	char *ptmp = strtok(tmp, ","); //第一次使用
	
	//求和
	int sum = 0;
	while(ptmp != NULL) //ptmp为空则表示tmp字符串切割完毕
	{
		int i;
		//sscanf(ptmp, "%d", &i); //从字符串ptmp按"%d"格式读取数据,存入&i
		i = atoi(ptmp); //atoi()将字符串ptmp转换成int型
		sum += i;
		ptmp = strtok(NULL, ","); //第二次使用,第一个参数为NULL
	}

	return sum;
}

int main()
{
	//每个字段都是一个整数,字段的数量随机,字段之间用","分割,求所有整数的和
	char a[100] = "12,43,65,13,97,54,19";

	int sum = get_sum(a);
	printf("sum = %d\n", sum);

	return 0;
}
