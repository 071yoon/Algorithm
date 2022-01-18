#include <stdio.h>

int main(){
	int num_arr[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	int	num, div, cnt, j;

	cnt = 0;
	for (int i = 0; i < 10; i++)
	{	
		scanf("%d", &num);
		div = num % 42;
		for (j = 0; j < 10; j++)
		{
			if (num_arr[j] == div)
				break ;
		}
		if (j == 10)
			num_arr[cnt++] = div;
	}
	printf("%d", cnt);
}