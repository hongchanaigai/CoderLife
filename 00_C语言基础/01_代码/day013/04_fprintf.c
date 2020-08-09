/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-08 23:00
 * Last modified  : 2020-08-08 23:00
 * Filename       : 04_fprintf.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h> //rand(),srand()
#include <time.h> //time()

int main()
{
	FILE *fp = fopen("4.txt", "w+"); //打开文件,写方式

	int i, num; 

	srand( (unsigned int)time(NULL) ); //设置随机种子

	for(i = 0; i < 10; ++i) //产生10个随机数
	{
		num = rand() % 100; //随机数控制在100以内
		fprintf(fp, "%d\n", num);
	}

	fclose(fp); //关闭文件

	return 0;
}
