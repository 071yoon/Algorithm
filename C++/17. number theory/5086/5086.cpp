#include <stdio.h>

int main(){
	long long num1, num2;

	num1 = 1;
	num2 = 1;
	while (1){
		scanf("%lld %lld", &num1, &num2);
		if (num1 == 0 && num2 == 0)
			return (0);
		if (num1 % num2 == 0 && num2 != 1)
			printf("multiple\n");
		else if (num2 % num1 == 0 && num1 != 1)
			printf("factor\n");
		else
			printf("neither\n");
	}
	return (0);
}