#include <stdio.h>

int main(){
	int	cnt, num, cmp;

	scanf("%d %d", &cnt, &num);
	for (int i = 0; i < cnt; i++)
	{
		scanf("%d", &cmp);
		if (cmp < num)
			printf("%d ", cmp);
	}
}