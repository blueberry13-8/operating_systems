#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(){
	int i1 = INT_MAX;
	unsigned short i2 = USHRT_MAX;
	long int i3 = LONG_MAX;
	float f1 = FLT_MAX;
	double d1 = DBL_MAX;
	printf("Size of int : %ld || Max value of int : %d\n", sizeof(i1), i1);
	printf("Size of unsigned short int : %ld || Max value of unsigned short int : %d\n", sizeof(i2), i2);
	printf("Size of signed long int : %ld || Max value of signed long int : %ld\n", sizeof(i3), i3);
	printf("Size of float : %ld || Max value of float : %f\n", sizeof(f1), f1);
	printf("Size of double : %ld || Max value of double : %f\n", sizeof(d1), d1);
}
