#include <stdio.h>

int factorial(int num){
	int ret;
	if (num == 0)
		return (1);
	else{
		ret = num * factorial(num - 1);
		return (ret);
	}
}
int main(){
	int num;
	scanf("%d", &num);
	printf("%d", factorial(num));
}