#include <stdio.h>

int main(){
	unsigned int A, B, C;
	int cnt;

	cnt = 0;
	scanf("%d %d %d", &A, &B, &C);
	if (B >= C){
		printf("-1");
		return (0);
	}
	else if (B == C){
		printf("0");
		return (0);
	}
	while (cnt <= A / (C - B)){
		cnt++;
	}
	printf("%d", cnt);
}