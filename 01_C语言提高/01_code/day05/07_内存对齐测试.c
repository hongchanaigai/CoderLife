#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//printf()
#include <stdlib.h>	//system()
#include <string.h>

int main(void)
{
	/*struct
	{
		double c;
		int a;
		short b;
	}A;*/
	/*
	c: 8*0 = 0
	a: 4*2 = 8	//4*0,4*1������
	b: 2*6 = 12	//2*0,2*1,2*2,2*3,2*4,2*5������

	00 01 02 03 04 05 06 07(�ڴ����,��8�ֽڶ���)
	 c  c  c  c  c  c  c  c

	08 09 10 11 12 13 14 15(�ڴ����,��8�ֽڶ���)
	 a  a  a  a  b  b  *  *
	*/

	struct
	{
		int a;
		double c;
		short b;
	}A;
	/*
	a: 4*0 = 0
	c: 8*1 = 8	//8*0������
	b: 2*8 = 16	//2*0,2*1,2*2,2*3,2*4,2*5,2*6,2*7������

	00 01 02 03 04 05 06 07(�ڴ����,��8�ֽڶ���)
	 a  a  a  a  *  *  *  *

	08 09 10 11 12 13 14 15(�ڴ����,��8�ֽڶ���)
	 c  c  c  c  c  c  c  c

	16 17 18 19 20 21 22 23(�ڴ����,��8�ֽڶ���)
	 b  b  *  *  *  *  *  *
	*/
	printf("%d\n", sizeof(A));

	printf("\n");
	system("pause");
	return 0;
}