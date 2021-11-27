#include <stdio.h>

int	isprime(int nb)
{
	int	i;
	int	num;

	num = nb;
	if (num < 2)
		return (0);
	if (num == 2)
		return (1);
	i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(){
	int num1, num2;

	scanf("%d %d", &num1, &num2);
	for (int i = num1; i <= num2; i++){
		if (isprime(i))
			printf("%d\n", i);
	}
}