/**********************************************************
 * Author         : huang
 * Creat modified : 2020-07-26 21:46
 * Last modified  : 2020-07-26 21:46
 * Filename       : mystrlen.c
 * Description    : 
 * *******************************************************/

int my_strlen(char str[])
{
	int i = 0;

	while(str[i] != '\0')
	{
		++i;
	}

	return i;
}
