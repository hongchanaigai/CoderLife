#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add()
{
	printf("\nadd11111111111");
}

void minus()
{
	printf("\nminus2222222222");
}

void multi()
{
	printf("\nmulti3333333333");
}

void divi()
{
	printf("\ndivi4444444444");
}

void myexit()
{
	exit(0);
}

int main(void)
{
#if 0
	char cmd[100] = { 0 };
	int ret = 0;

	while (1)
	{
		printf("\nplease enter command: ");
		ret = scanf("%s", cmd);

		if (strcmp(cmd, "add") == 0)
		{
			add();
		}
		else if (strcmp(cmd, "minus") == 0)
		{
			minus();
		}
		else if (strcmp(cmd, "multi") == 0)
		{
			multi();
		}
		else if (strcmp(cmd, "divi") == 0)
		{
			divi();
		}
		else if (strcmp(cmd, "myexit") == 0)
		{
			myexit();
		}
		else if (strcmp(cmd, "add") == 0)
		{
			add();
		}
	}
#endif // 0

	/*void(*fun1)() = add;
	fun1();*/

	//函数指针数组
	void(*fun[5])() = { add, minus, multi, divi, myexit };

	//指针数组
	char* buf[] = { "add", "min", "mul", "div", "exit" };

	char cmd[100] = { 0 };
	int ret = 0;
	int i = 0;

	while (1)
	{
		printf("\nplease enter command: ");
		ret = scanf("%s", cmd);

		for (i = 0; i < 5; ++i)
		{
			if (strcmp(cmd, buf[i]) == 0)
			{
				fun[i]();
				break;	//跳出for循环
			}
		}
	}

	printf("\n");
	system("pause");
	return 0;
}