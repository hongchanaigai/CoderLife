/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-25 16:28
 * Last modified  : 2020-07-25 17:01
 * Filename       : 00_homework_猜数字.c
 * Description    : 
 * *******************************************************/

#include <stdio.h>
#include <stdlib.h> //srand(), rand()
#include <time.h> //time()
#include <unistd.h> //sleep()

int main()
{

	printf("/////////////guess the number of game/////////////\n");
	printf("The system will generate a random number of four bits\n");

	//产生一个4位随机数
	int num = 0, i, n;

	srand((unsigned int)time(NULL)); //随机数种子
	while(num < 1000) //排除第一位随机数为0的情况
	{
		num = rand() % 10000; //使随机数为四位
	}
	//printf("num = %d\n", num);

	//取出4位随机数的每一位,存在num1, num2, num3, num4中
	/*
	int num1, num2, num3, num4;
	num1 = num / 1000;
	num2 = (num % 1000) / 100;
	num3 = ((num % 1000) % 100) / 10;
	num4 = ((num % 1000) % 100) % 10;
	//printf("num1 = %d, num2 = %d, num3 = %d, num4 = %d\n", num1, num2, num3, num4);
	*/
	int rand_num[4];
	rand_num[0] = num / 1000;
	rand_num[1] = (num % 1000) / 100;
	rand_num[2] = ((num % 1000) % 100) / 10;
	rand_num[3] = ((num % 1000) % 100) % 10;

	//获取键盘输入的4位随机数,每一位存在guess1,guess2,guess3,guess4中
	//int guess, guess1, guess2, guess3, guess4;
	int guess, guess_num[4];
	while(1)
	{
		printf("please input a number(1234): ");
		scanf("%d", &guess);
		while(guess < 1000 || guess > 10000) //输入不合法,提示重新输入
		{
			printf("the number is error!!! enter again: ");
			scanf("%d", &guess);
		}

		/*
		guess1 = guess / 1000;
		guess2 = (guess % 1000) / 100;
		guess3 = ((guess % 1000) % 100) / 10;
		guess4 = ((guess % 1000) % 100) % 10;
		*/
		guess_num[0] = guess / 1000;
		guess_num[1] = (guess % 1000) / 100;
		guess_num[2] = ((guess % 1000) % 100) / 10;
		guess_num[3] = ((guess % 1000) % 100) % 10;
		//printf("guess = %d\n", guess);
		//printf("guess1 = %d, guess2 = %d, guess3 = %d, guess4 = %d\n", guess1, guess2, guess3, guess4);

		//比较guess和num的每一位数
		n = 0;
		for(i = 0; i < 4; ++i)
		{
			if(guess_num[i] > rand_num[i])
			{
				printf("the %d number is too big\n", i+1);
			}
			else if(guess_num[i] < rand_num[i])
			{
				printf("the %d number is too small\n", i+1);
			}
			else
			{
				printf("the %d number is right\n", i+1);
				++n;
			}
		}

		if(4 == n) //4位数字均3猜对,退出循环
		{
			printf("congratulations!!! you got it!!!\n");
			sleep(2);
			return 0; //结束程序
		}
	}

	return 0;
}
