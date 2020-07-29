/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-25 18:56
 * Last modified  : 2020-07-25 19:16
 * Filename       : 04_字符串拷贝.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>
#include <string.h> //strcpy(), strncpy()

int main00()
{
	char src[100] = "hello huang"; //源字符串
	char dst[100]; //目的

	//功能:把src字符数组的内容拷贝给dst所代表的数组
	strcpy(dst, src);

	printf("dst = %s\n", dst);


	char src1[100] = "hello\0 huang"; //源字符串
	char dst1[100]; //目的

	//功能:把src字符数组的内容拷贝给dst所代表的数组
	//拷贝原理:从首元素开始,遇到结束符'\0'结束
	strcpy(dst1, src1);

	printf("dst1 = %s\n", dst1);

	return 0;
}


int main()
{
	char src[100] = "hello huang"; //源字符串
	//char dst[100] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; //目的
	char dst[100];

	//功能:把src字符数组的前strlrn(src)个内容拷贝给dst所代表的数组
	//可以把'\0'拷贝过去,之后的内容就无法拷贝
	//strncpy(dst, src, strlen(src));
	//strncpy(dst, src, strlen(src)+1);
	strncpy(dst, src, sizeof(src));

	printf("dst = %s\n", dst);
	//printf("dst = %s\n", dst+6);
	printf("dst = %s\n", dst+strlen("hello")+1);

	return 0;
}
