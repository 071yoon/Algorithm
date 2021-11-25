#include <stdio.h>

int main(){
	int *num_arr;
	int	sz, cnt, avg, sum, many;

	scanf("%d", &sz);
	for (int i = 0; i < sz; i++){
		sum = 0;
		avg = 0;
		scanf("%d", &cnt);
		num_arr = new int[cnt];
		for (int i = 0; i < cnt; i++)
		{
			scanf("%d", &num_arr[i]);
			sum += num_arr[i];
		}
		avg = sum / cnt;
		many = 0;
		for (int i = 0; i < cnt; i ++)
		{
			if (num_arr[i] > avg)
				many++;
		}
		printf("%.3lf%%\n", ((float)many / (float)cnt) * 100);
	}
}