#include <stdio.h>

int main(){
	int H, W, num, cnt;
	int x, y;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d %d %d", &H, &W, &num);
		x = num / H + 1;
		if (num % H == 0)
			x--;
		y = num % H;
		if (y == 0)
			y = H;
		printf("%d", y);
		if (x >= 1 && x <= 9)
			printf("0%d\n", x);
		else
			printf("%d\n", x);
	}
}