#include <stdio.h>

int main()
{
	int A, B, C, num;
	int	num_arr[10] = {0};

	scanf("%d %d %d", &A, &B, &C);
	A = A * B * C;
	while (A)
	{
		num = A % 10;
		A = A / 10;
		num_arr[num]++;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", num_arr[i]);
}