/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-07 20:18
 * Last modified  : 2020-08-07 20:18
 * Filename       : 09_myvim.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //strncmp()

int main(int argc, char *argv[])
{
	//以写方式打开文件
	FILE *fp = fopen(argv[1], "w");

	//从键盘读取内容,放在字符数组
	//字符数组内容,一个一个字符往文件写
	char buf[1024];
	while(1)
	{
		//默认遇到换行符,此次结束读取,换行符都放在buf
		//fgets()按行读取
		fgets(buf, sizeof(buf), stdin);
		//如果用户输入的内容为:wq,结束,保存文件
		if(strncmp(buf, ":wq", 3) == 0)
		{
			break;
		}

		int i = 0;
		while(buf[i] != '\0')
		{//读取的内容没有到结束符,读取到的内容写入文件
			fputc(buf[i], fp);
			++i;
		}
	}

	//关闭文件
	fclose(fp);


	return 0;
}
