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
	int cnt, num;
	
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d", &num);
		int half_up = num / 2;
		int half_down = half_up;
		if (isprime(half_up)){
			printf("%d %d\n", half_up, half_up);
		}
		else{
			while (!(isprime(half_down) && isprime(half_up))){
				half_down--;
				half_up++;
			}
			printf("%d %d\n", half_down, half_up);
		}
	}
}