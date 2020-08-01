/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-01 19:58
 * Last modified  : 2020-08-01 19:58
 * Filename       : 15_查找匹配字符串出现的次数.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //strstr(),strlen()

int main()
{
	char *p = "816abcd297759abcd803657abcd7828abcd230982037";
	int i = 0;
	char *tmp = NULL;

	while(1)
	{
		//查找匹配字符串,如果找到,返回匹配字符串的地址,没有找到返回NULL
		tmp = strstr(p, "abcd");
		if(tmp == NULL)
		{
			break; //跳出循环
		}
		else //找到
		{
			++i; //累加
			
			//重新设置寻找起点
			p = tmp + strlen("abcd");
		}

	}
	
	printf("出现abcd的次数为: %d\n", i);

	return 0;
}
