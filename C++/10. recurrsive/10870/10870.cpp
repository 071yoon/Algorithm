#include <stdio.h>

int fibo(int num){
	int ret;
	if (num == 1 || num == 2)
		return (1);
	else if (num < 1){
		return (0);
	}
	ret = fibo(num - 1) + fibo(num - 2);
	return (ret);
}

int main(){
	int num, ret;

	scanf("%d", &num);
	ret = fibo(num);
	printf("%d", ret);
}