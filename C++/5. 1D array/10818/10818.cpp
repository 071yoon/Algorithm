#include <stdio.h>

int main(){
	int	num, max, min, cnt;

	scanf("%d", &cnt);
	max = -1000000;
	min = 1000000;
	for (int i = 0; i < cnt; i++)
	{
		scanf("%d", &num);
		if (num > max)
			max = num;
		if (num < min)
			min = num;
	}
	printf("%d %d", min, max);
}