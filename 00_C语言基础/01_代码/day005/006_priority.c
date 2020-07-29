/**********************************************************
 * Author         : huang
 * Creat modified : 2020-06-26 16:24
 * Last modified  : 2020-06-26 16:59
 * Filename       : 006_priority.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[]){
	/*
	 3)短路规则(优化)
	 ||,左边为真,右边不执行
	 &&,左边为假,右边不执行
	*/
	
	int c = 0;
	printf("before c = %d\n", c);
	
	//||左边为真,右边不执行
	//1)||优先级高于=
	//2)先算1 || c,结果为真,1
	//3)再算1 = 250,常量不能修改
	//1 || c = 250;	//error

	1 || (c = 250);
	printf("after c = %d\n", c);

	0 || (c = 250);
	printf("after c = %d\n", c);

	return 0;
}
