/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-26 18:15
 * Last modified  : 2020-07-26 18:46
 * Filename       : 11_字符串切割.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>
#include <string.h> //strtok()

int main()
{
	char buf[] = "abc,mike,huang,250,hehehe,hello";
	char tmp[100];

	strcpy(tmp, buf); //把buf内容拷贝到tmp数组,后面使用tmp
	
	char *p;

	//第一次调用
	p = strtok(tmp, ",");
	while(p != NULL) //说明切割成功
	{
		printf("p = %s\n", p);

		//第二次起,第一个参数需要写NULL
		p = strtok(NULL, ",");
	}

	return 0;
}

int main01()
{
	char buf[] = "abc,mike,huang,250";
	char tmp[100];

	strcpy(tmp, buf); //把buf内容拷贝到tmp数组,后面使用tmp
	
	//第一个调用
	//第一个参数写源字符串,第二个参数写切割字符
	//返回值就是切割后的字符串
	//如果没有切割成功,返回NULL
	//在匹配切割字符的地方,换成结束符'\0'
	//使用strtok()会破坏原来字符串的结构
	//printf("buf[3] = %d\n", buf[3]);
	char *p = strtok(tmp, ",");
	printf("p1 = %s\n", p);
	//printf("buf = %s\n", buf);
	//printf("buf[3] = %d\n", buf[3]);
	
	//第二次调用起,第一个参数需要写NULL
	p = strtok(NULL, ",");
	printf("p2 = %s\n", p);

	return 0;
}
