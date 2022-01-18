#include <stdio.h>

int main(){
	int	cnt, max, num;

	max = 0;
	for(int i = 1; i < 10; i++)
	{
		scanf("%d", &num);
		if (num > max)
		{
			max = num;
			cnt = i;
		}
	}
	printf("%d\n%d", max, cnt);
}