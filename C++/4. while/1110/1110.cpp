#include <stdio.h>

int main(){
	int	org, new_num, cnt, num;

	cnt = 0;
	scanf("%d", &org);
	new_num = -1;
	num = org;
	while (org != new_num)
	{
		new_num = ((num % 10) * 10) + (((num % 10) + (num / 10)) % 10);
		cnt++;
		num = new_num;
	}
	printf("%d", cnt);
	return (0);
}