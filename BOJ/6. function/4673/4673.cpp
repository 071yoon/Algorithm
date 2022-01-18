#include <stdio.h>

int addr(int num){
	int ret;
	ret = num;
	while (num){
		ret += (num % 10);
		num /= 10;
	}
	return (ret);
}

int main(){
	bool arr[10001] = {0};
	int tmp;
	for (int i = 1; i < 10001; i++){
		tmp = addr(i);
		if (tmp < 10001)
			arr[tmp] = 1;
	}
	for (int i = 1; i < 10001; i++)
	{
		if (!arr[i])
			printf("%d\n", i);
	}
}