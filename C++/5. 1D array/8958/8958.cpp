#include <stdio.h>

int main(){
	int	sz, num_cnt, tot;
	int	*score_arr;
	char OX[80] = {0};

	scanf("%d", &sz);
	score_arr = new int[sz];
	for (int i = 0; i < sz; i++)
	{
		scanf("%s", OX);
		num_cnt = 0;
		tot = 0;
		for (int j = 0; j < sizeof(OX); j++)
		{
			if (OX[j] == 'O'){
				num_cnt++;
				tot += num_cnt;
			}
			else if (OX[j] == 'X'){
				num_cnt = 0;
			}
			else
				break ;
		}
		score_arr[i] = tot;
	}
	for (int i = 0; i < sz; i++)
	{
		printf("%d\n", score_arr[i]);
	}
	delete[] score_arr;
}