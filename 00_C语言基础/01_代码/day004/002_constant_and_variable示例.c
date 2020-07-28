//002_constant_and_variable.c
#include <stdio.h>
//1、#开头的语句是预处理语句，无需分号结束
//2、定义一个宏定义的标识符MAX，它代表100，MAX是常量
//3、宏定义以后的代码都可以使用MAX
//4、在后面出现的MAX，预处理都会替换成100
#define MAX 100

int main(int argc, char *argv[]){
	//10 = 1;
	//MAX = 1;	//MAX是常量，不允许修改
	MAX;
	MAX;

	int b = MAX;

	//const是一个关键字，作用是修饰一个变量为只读
	const int c = 10;
	//c = 100;	//error，c只读，不允许修改

	int d;
	d = 100;	//ok，变量可以修改

	int e = c;	//把c的值给e，c本身没有改变
	
	return 0;
}
