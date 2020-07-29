/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 21:29
 * Last modified  : 2020-07-20 21:29
 * Filename       : 20_字符数组.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	//1. C语言没有字符串类型,用字符数组模拟
	char a[10];

	//2. 字符串一定是字符数组,字符数组不一定是字符串
	//3. 如果字符数组是以字符'\0'(等价于数字0)结尾,那么这个字符数组就是字符串
	char b[] = {'a', 'b', 'c'};	//字符数组
	char c[] = {'a', 'b', 'c', '\0'};	//字符串
	char d[] = {'a', 'b', 'c', 0};	//字符串
}
