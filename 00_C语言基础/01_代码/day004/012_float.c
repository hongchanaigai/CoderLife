//012_float.c
#include <stdio.h>

int main(int argc, char *argv[]){
	float a;
	printf("please enter a float: ");
	scanf("%f", &a);
	printf("a = %f\n", a);

	double b;
	b = 3.14;
	printf("b = %lf\n", b);

	return 0;
}
