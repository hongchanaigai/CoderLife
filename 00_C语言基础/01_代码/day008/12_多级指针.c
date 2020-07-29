/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-28 22:17
 * Last modified  : 2020-07-28 22:17
 * Filename       : 12_多级指针.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	//如何定义一个合适类型的变量保存另一个变量的地址
	//在需要保存变量地址的类型基础上加一个*
	int a = 10;
	int *pa = &a;
	int **ppa = &pa;
	int ***pppa = &ppa;
	int ****ppppa = &pppa;

	*ppppa;
	**ppppa;
	***ppppa;
	****ppppa;
	*pppa;
	**pppa;
	***pppa;

	return 0;
}
