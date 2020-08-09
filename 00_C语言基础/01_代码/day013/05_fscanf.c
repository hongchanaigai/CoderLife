/**********************************************************
 * Author         : huang
 * Creat modified : 2020-08-08 23:09
 * Last modified  : 2020-08-08 23:09
 * Filename       : 05_fscanf.c
 * Description    : 
 * *******************************************************/
#include <stdio.h>

int main()
{
	FILE *fp = fopen("4.txt", "r+");

	int num;

	while(1)
	{
		fscanf(fp, "%d\n", &num);
		printf("num = %d\n", num);

		if( feof(fp) )
		{
			break;
		}
	}

	fclose(fp);

	return 0;
}
