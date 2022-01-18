#include <stdio.h>
#include <algorithm>

int main(){
	int num[4][2];
	for (int i = 0; i < 3; i++)
		scanf("%d %d", &num[i][0], &num[i][1]);
	for(int i = 0; i < 2; i++){
		if (num[0][i] == num[1][i])
			num[3][i] = num[2][i];
		else if (num[0][i] == num[2][i])
			num[3][i] = num[1][i];
		else if (num[1][i] == num[2][i])
			num[3][i] = num[0][i];
	}
	printf("%d %d", num[3][0], num[3][1]);
}