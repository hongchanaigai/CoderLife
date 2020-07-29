/**********************************************************
 * Author         : huang
 * Creat modified : 2020-06-26 16:03
 * Last modified  : 2020-06-26 16:03
 * Filename       : 005_comparison_operator.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[]){
	//因为4 == 3条件为假,所以结果为0
	printf("4 == 3 result is: %d\n", 4 == 3);
	
	//因为4 > 3条件为真,所以结果为1
	printf("4 > 3 result is: %d\n", 4 > 3);

	printf("!(4 == 3) result is: %d\n", !(4 == 3));

	//&&,左右结果都为真,整体结果为真
	printf("1 && -1 result is: %d\n", 1 && -1);
	printf("1 && 0 result is: %d\n", 1 && 0);

	//||,左右结果都为假,整体结果为假
	//||,只要有一边为真,整体结果为假
	printf("1 || 0 result is: %d\n", 1 || 0);
	printf("0 || 0 result is: %d\n", 0 || 0);

	return 0;
}
