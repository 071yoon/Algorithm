#include <stdio.h>

int main()
{
	int		cnt, num, max;
	float	sum;
	float	*num_arr;

	scanf("%d", &cnt);
	max = 0;
	sum = 0;
	num_arr = new float[cnt];
	for (int i = 0; i < cnt; i++)
	{
		scanf("%d", &num);
		num_arr[i] = num;
		if (num > max)
			max = num;
	}
	for (int i = 0; i < cnt; i++)
	{
		sum += ((float)num_arr[i] / (float)max)* 100;
	}
	sum /= cnt;
	printf("%.5lf", sum);
	delete[] num_arr;
}