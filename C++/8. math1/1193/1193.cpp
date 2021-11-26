#include <stdio.h>

int main(){
	int num, cnt, target, bunmo, bunja, sign;

	cnt = 2;
	sign = -1;
	target = 1;
	scanf("%d", &num);
	while (num > target){
		target += cnt;
		cnt += 1;
		sign *= -1;
	}
	cnt -= 1;
	bunmo = target - num + 1;
	bunja = cnt - (bunmo - 1);
	if (sign == 1)
		printf("%d/%d", bunja, bunmo);
	else
		printf("%d/%d", bunmo, bunja);
}