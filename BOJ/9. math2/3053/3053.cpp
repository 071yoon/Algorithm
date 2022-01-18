#include <stdio.h>
#include <math.h>

int main(){
	double num;

	scanf("%lf", &num);
	printf("%.6f\n", num * num * M_PI);
	printf("%.6f\n", num * num * 2);
}