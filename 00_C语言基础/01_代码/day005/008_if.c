/**********************************************************
 * Author         : huang
 * Creat modified : 2020-06-26 17:10
 * Last modified  : 2020-06-26 17:29
 * Filename       : 008_if.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[]){
	//1)if是一个关键字,if后面有(),if()后面没有分号
	//2)()里写的是条件,条件为真,执行if语句,为假不执行
	//if(1){	//条件为真
	//if(0){	//条件为假
	if(4 > 3){	//条件为真
		printf("meet the conditions.\n");
	}

	//3)if()后面最好加{},{}代表if语句
	//4)if()后面如果不加,只有第一个语句属于if
	if(0)
		printf("test1:11111111111\n");
	printf("test2:222222222\n");	//此语句不属于if

	//5)if()后面没有分号,切记
	if(0);	//if()有分号
	{
		printf("aaaaaaaaaa\n");
	}

	//等价于下面
	if(0)
		;	//if()下面是一个空语句
	{
		printf("aaaaaaaaaa\n");	//此语句和if没关系,无条件顺序执行
	}

	int a = 3;
	//1)把4赋值给a,a的值变为4
	//2)判断a的值是不是真,如果为真,执行语句,不为真,不执行
	//if(a = 4){
	//if(a == 4){
	if(4 == a){	//推荐些这种,常量放在左边
		printf("a == 4\n");
	}

	return 0;
}
