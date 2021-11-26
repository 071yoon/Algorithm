#include <stdio.h>

int main(){
	int num, cnt, sixth, ret;

	scanf("%d", &num);
	cnt = 1;
	ret = 1;
	sixth = 6;
	while (num > cnt){
		cnt += sixth;
		sixth += 6;
		ret++;
	}
	printf("%d", ret);
}