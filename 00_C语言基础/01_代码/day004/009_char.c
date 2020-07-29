//009_char.c
#include <stdio.h>

int main(int argc, char *argv[]){
	//1)内存中没有字符,只有数字
	//2)一个数字,对应一个字符,这种规则就是ASCII
	//3)使用字符或数字给字符变量赋值是等价的
	//4)字符类型本质上就是1个字节大小的整型
	
	//字符:'一个字符'
	char ch = 'a';
	printf("ch1 = %c, ch = %d\n", ch, ch);

	ch = 97;	//以ASCII赋值,和ch = 'a'等价
	printf("ch2 = %c\n", ch);

	//小写字母比大写字母大32
	char a = 'A';
	char b = 'a';
	printf("A = %d, a = %d\n", a, b);

	//小写转大写,小写字母-32
	printf("lowercase to uppercase: %c\n", 'a' - 32);

	//大写转小写,大写字母+32
	printf("uppercase to lowercase: %c\n", 'A' + 32);

	char tmp;
	printf("please enter a char: ");
	scanf("%c", &tmp);
	printf("tmp = %c\n", tmp);

	return 0;
}
