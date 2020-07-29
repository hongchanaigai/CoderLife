//008_definition_and_output_of_int_variable.c
#include <stdio.h>

int main(int argc, char * argv[]){
	int a;
	printf("please enter a: ");	//输出
	//scanf("please enter a: %d");	//error
	//阻塞,等待用户输入内容,按回车结束
	//scanf("%d\n", &a);//error,没有\n
	scanf("%d", &a);	//输入

	printf("a = %d\n", a);


	//short占2字节
	//short b;
	short int b;
	printf("please enter b: ");	//输出
	//%hd代表是短整型
	scanf("%hd", &b);
	printf("b = %d\n", b);

	//long long 占8字节
	long long int c;
	printf("please enter c: ");
	scanf("%lld", &c);
	printf("c = %lld\n", c);

	return 0;
}
