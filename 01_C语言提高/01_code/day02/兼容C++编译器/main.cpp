#include <stdio.h>
#include <stdlib.h>	//system()
#include "socketclient.h"

int main(void)
{
	socketclient_init(NULL);

	printf("\n");
	system("pause");
	return 0;
}