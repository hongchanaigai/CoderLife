/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-08 21:08
 * Last modified  : 2020-08-08 21:08
 * Filename       : 01_文件版四则运算.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>
#include <string.h> //memset(),strlen(),strcat

void write_file()
{
	//打开文件
	FILE *fp = fopen("1.txt", "w");

	//写文件
	fputs("10+10=\n", fp);
	fputs("10-10=\n", fp);
	fputs("10*10=\n", fp);
	fputs("10/10=\n", fp);
	fputs("10+5=\n", fp);
	fputs("10-5=\n", fp);
	fputs("10*5=\n", fp);
	fputs("10/5=\n", fp);

	//关闭文件
	fclose(fp);
}

int calc(int a, int b, char ch)
{
	switch(ch)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		default:
			return 0;
	}

	return 0;
}

void read_file()
{
	//打开文件
	FILE *fp = fopen("1.txt", "r");

	//读文件
	char buf[1024];
	char tmp[1024 * 4] = {0}; 
	while(1)
	{
		memset(buf, 0, sizeof(buf)); //清空内存,方便测试程序
		//遇到\n,文件结束符,出错,结束本次读取
		fgets(buf, sizeof(buf), fp);
		if(strlen(buf) > 0) //防止最后一次出现无用字符
		{
			//printf("buf = %s\n", buf);
			int a, b;
			char ch;
			sscanf(buf, "%d%c%d=\n", &a, &ch, &b);
			//printf("%d%c%d=%d\n", a, ch, b, calc(a,b,ch));
			sprintf(buf, "%d%c%d=%d\n", a, ch, b, calc(a,b,ch));
			//printf("buf = @%s@", buf);
			strcat(tmp, buf);
		}

		//如果文件结束,跳出循环
		if(feof(fp))
		{
			break;
		}
	}

	//printf("%s", tmp);

	//关闭文件
	fclose(fp);

	//关闭文件后重新以写方式打开文件,目的是清空文件,重新写入
	fp = fopen("1.txt", "w");
	fputs(tmp, fp);
	fclose(fp);
}

int main()
{
	write_file();

	read_file();

	return 0;
}
