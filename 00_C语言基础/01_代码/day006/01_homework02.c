/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 15:31
 * Last modified  : 2020-07-20 15:43
 * Filename       : 01_homework02.c
 * Description    : 从键盘输入1~7的数字,分别提示星期一~星期日,其他输入,提示错误
 * *******************************************************/

#include <stdio.h>

int main()
{
	int num;
	printf("please input a number: ");
	scanf("%d", &num);

	switch(num)
	{
		case 1:
			printf("momday\n");
			break;
		case 2:
			printf("tuesday\n");
			break;
		case 3:
			printf("wednesday\n");
			break;
		case 4:
			printf("thursday\n");
			break;
		case 5:
			printf("friday\n");
			break;
		case 6:
			printf("saturday\n");
			break;
		case 7:
			printf("sunday\n");
			break;
		default:
			printf("input error!!!\n");
			break;
	}

	return 0;
}
