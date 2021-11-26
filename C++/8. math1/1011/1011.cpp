#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	double cnt, num1, num2, var, org;

	scanf("%lf", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%lf %lf", &num1, &num2);
		var = abs(num2 - num1);
		org = var;
		var = (int)(sqrt(var));
		if (!(org >= ((var * var) - var - 1) && org <= ((var * var) + var)))
			var += 1;
		if (org <= var * var){
			printf("%d\n", (int)((2 * var) - 1));
		}
		else
			printf("%d\n", (int)((2 * var)));
	}
}