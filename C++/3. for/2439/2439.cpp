#include <stdio.h>

int main(){
	int	cnt;

	scanf("%d", &cnt);
	for (int i = 1; i < (cnt + 1); i++)
	{
		for (int j = 0; j < cnt - i; j++)
			printf(" ");
		for (int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}
}