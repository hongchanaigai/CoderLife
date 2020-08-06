/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-05 15:28
 * Last modified  : 2020-08-05 15:28
 * Filename       : type_game.c
 * Description    : 简单的字母输入测试程序
 * *******************************************************/
#include <stdio.h>
#include <time.h> //time()
#include <stdlib.h> //srand(),rand(),system()

#include "my_getch.h" //my_getch()

#define MAX 51 //定义测试字母最大长度

void help() //游戏说明菜单
{
	printf("\n***********************************************");
	printf("\n*   输入过程中无法退出,输入出错则以 _ 表示!   *");
	printf("\n*   按任意键开始测试,按下首字母时开始计时!!   *");	
	printf("\n***********************************************\n\n");
}

void start(char *str) //产生随机字母
{
	srand((unsigned int)time(NULL)); //随机种子
	int i;

	for(i = 0; i < MAX-1; ++i) //打印MAX-1(50)个英文字母用于测试
	{
		*(str+i) = rand() % 26 + 'a';
	}

	*(str + MAX-1) = '\0'; //写完字符后补上结束符标志位
}

void on_game(char *str) //开始游戏
{
	char ch;
	int i = 0;
	int count = 0;
	time_t t_start, t_end;

	system("clear"); //先清屏
	printf("\n%s\n", str);

	count = 0;
	for(i = 0; i < MAX-1; ++i)
	{
		ch = my_getch();
		if(0 == i)
		{
			t_start = time(NULL); //当前系统时间为开始时间
		}

		if(ch == *(str+i))
		{
			printf("%c", ch);
			++count;
		}
		else
		{
			printf("_"); //打印出错标志_
		}
	}

	t_end = time(NULL); //当前系统时间为结束时间

	printf("\n完成输入!\n用时 %ld s\n", t_end - t_start);
	printf("正确率 %lf %%\n", (count*1.0 / (MAX-1)) * 100);
	printf("按下Esc键退出,任意键继续!\n\n");
}

int main()
{
	char str[MAX] = {0};

	while(1)
	{
		help(); //游戏说明菜单
		start(str); //产生随机字母
		my_getch(); //读取用户键盘输入
		on_game(str); //开始游戏

		char ch = my_getch();

		if(27 == ch) //Esc的ASCII码为27
		{
			break; //退出循环
		}

		system("clear"); //先清屏
	}

	return 0;
}
