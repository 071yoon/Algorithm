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
	int first, second, sum, flag, tmp;

	flag = 0;
	tmp = 0;
	sum = 0;
	scanf("%d", &first);
	scanf("%d", &second);
	for (int i = first; i <= second; i++){
		if ((flag == 0) && isprime(i)){
			flag = 1;
			tmp = i;
		}
		if (isprime(i)){
			sum += i;
		}
	}
	if (flag == 1){
		printf("%d\n%d", sum, tmp);
	}
	else{
		printf("-1");
	}
}