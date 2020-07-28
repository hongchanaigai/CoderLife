//010_escape_character.c
#include <stdio.h>

int main(int argc, char *argv[]){
	//字符,原则上'',内部只有一个字符,转义字符除外
	//char a = 'abc';	//warning,不合理
	
	//转义字符,由反斜杠\组成的多个字符
	char ch = '\n';	//换行符
	printf("abc%c", ch);

	ch = '\r';	//光标切换到句首
	printf("fffefghi\n");
	printf("fff%cefghi\n", ch);

	ch = '\b';	//退格
	printf("123456\n");
	printf("123%c456\n", ch);

	return 0;
}
