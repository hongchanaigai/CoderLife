/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-20 16:31
 * Last modified  : 2020-07-20 16:54
 * Filename       : 04_homework05.c
 * Description    : 任意给出一个年\月\日,判断是这一年的第几天
 * *******************************************************/

#include <stdio.h>

int main()
{
	int total = 0;
	int day = 0, month = 0, year = 0;

	printf("please input: year month day\n");
	scanf("%d %d %d", &year, &month, &day);

	switch(month)
	{
		case 1:
			total = 0;
			break;
		case 2:
			total = 31;
			break;
		case 3:
			total = 59;
			break;
		case 4:
			total = 90;
			break;
		case 5:
			total = 120;
			break;
		case 6:
			total = 151;
			break;
		case 7:
			total = 181;
			break;
		case 8:
			total = 212;
			break;
		case 9:
			total = 243;
			break;
		case 10:
			total = 273;
			break;
		case 11:
			total = 304;
			break;
		case 12:
			total = 334;
			break;
		default:
			printf("input error!!!\n");
			break;
	}

	total += day;
	if(month > 2 && ((year%4 == 0 && year%100 != 0) || (year%400 == 0)))
	{
		total += 1;
	}

	printf("%d-%d-%d is %dth day.\n", year, month, day, total);

	return 0;
}
