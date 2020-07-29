/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-29 17:03
 * Last modified  : 2020-07-29 17:03
 * Filename       : 16_万能指针.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>

int main()
{
	//1. 不可以定义void类型的普通变量,不能确定类型
	//void a; //error
	
	//2. 可以定义void *变量,void *指针也叫万能指针
	//3. void *可以指向任何类型的变量,使用指针所指向的内存时,最好转换为它本身的指针类型
	void *p = NULL;
	int a = 10;
	p = &a;
	//*p = 222; //error
	*( (int *)p ) = 222;
	//printf("*p = %d\n", *p); //error
	printf("*p = %d\n", *( (int *)p ));

	return 0;
}
