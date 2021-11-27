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
	int cnt, ret, now;

	scanf("%d", &cnt);
	ret = 0;
	for (int i = 0; i < cnt; i++){
		scanf("%d", &now);
		if (isprime(now))
			ret++;
	}
	printf("%d", ret);
}