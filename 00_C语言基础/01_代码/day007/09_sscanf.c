/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-26 17:04
 * Last modified  : 2020-07-26 17:09
 * Filename       : 09_sscanf.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	int a, b, c;
	printf("please enter a, b, c: ");
	scanf("%d %d %d", &a, &b, &c); //默认以空格标识
	printf("a0 = %d, b0 = %d, c0 = %d\n", a, b, c);

	char buf[] = "1 2 3";
	//从buf中以指定格式提取内容
	sscanf(buf, "%d %d %d", &a, &b, &c);
	printf("a1 = %d, b1 = %d, c1 = %d\n", a, b, c);

	//提取整型变量是最方便的
	char str[] = "a = 2, b = 3, c = 4";
	sscanf(str, "a = %d, b = %d, c = %d", &a, &b, &c);
	printf("a2 = %d, b2 = %d, c2 = %d\n", a, b, c);

	char str2[] = "3,4,5";
	sscanf(str2, "%d,%d,%d", &a, &b, &c);
	printf("a3 = %d, b3 = %d, c3 = %d\n", a, b, c);

	char tmp[] = "abc mike 250"; //提取字符串,默认以空格分隔,可以提取
	char arr1[10], arr2[10], arr3[10];
	sscanf(tmp, "%s %s %s", arr1, arr2, arr3); //不用&,数组名就是首元素地址
	printf("arr1 = %s, arr2 = %s, arr3 = %s\n", arr1, arr2, arr3);

	char tmp1[] = "abc,mike,250"; //提取字符串
	char brr1[10], brr2[10], brr3[10];
	sscanf(tmp1, "%s,%s,%s", brr1, brr2, brr3); //不用&,数组名就是首元素地址
	printf("brr1 = %s, brr2 = %s, brr3 = %s\n", brr1, brr2, brr3);

	return 0;
}
