/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-30 21:44
 * Last modified  : 2020-07-30 21:44
 * Filename       : 08_字符串拷贝函数.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

//void my_strcpy(char dst[], char src[])
void my_strcpy(char *dst, char *src)
{
	int i = 0;
	while(src[i] != '\0')
	{
		dst[i] = src[i];
		++i;
	}
	//结束符
	dst[i] = '\0';
}

int main()
{
	char src[] = "hello huang";
	char dst[100];
	char *p = dst;

	//my_strcpy(dst, src); //调用自定义的拷贝函数
	my_strcpy(p, src);
	printf("dst = %s\n", dst);

	return 0;
}
