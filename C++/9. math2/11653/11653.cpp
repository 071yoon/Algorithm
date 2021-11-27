#include <stdio.h>

int main(){
	int num, org;

	scanf("%d", &num);
	org = num;
	int i = 2;
	while (i < org / 2){
		if (num % i == 0){
			printf("%d\n", i);
			num /= i;
			i = 2;
		}
		else
			i++;
	}
	if (num != 1)
		printf("%d", num);
}