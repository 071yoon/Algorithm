#include <stdio.h>

int find_han(int num)
{
	int arr[3] = {0};
	int cnt = 0;

	if (num == 1000)
		return (0);
	while (num)
	{
		arr[cnt] = num % 10;
		cnt++;
		num /= 10;
	}
	if (cnt == 1 || cnt == 2)
		return (1);
	else if (cnt == 3)
	{
		if ((arr[0] - arr[1]) == (arr[1] - arr[2]))
			return (1);
		else
			return (0);
	}
	return (0);
}

int main(){
	int num, cnt;

	scanf("%d", &num);
	cnt = 0;
	for (int i = 1; i <= num; i++){
		if (find_han(i))
			cnt++;
	}
	printf("%d", cnt);
}