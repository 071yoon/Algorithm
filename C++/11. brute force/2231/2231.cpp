#include <stdio.h>
#include <algorithm>

int get_crt(int num){
	int sum;

	sum = num;
	while (num){
		sum += num % 10;
		num /= 10;
	}
	return (sum);
}

int main(){
	int num;
	
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		if (get_crt(i) == num){
			printf("%d", i);
			return (0);
		}
	}
	printf("0");
}