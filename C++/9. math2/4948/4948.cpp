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
	int num;

	num = 1;
	while (1){
		int cnt = 0;
		scanf("%d", &num);
		if (num == 0)
			return (0);
		for (int i = num + 1; i <= 2 * num; i++){
			if (isprime(i))
				cnt++;
		}
		printf("%d\n", cnt);
	}
}