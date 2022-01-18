#include <stdio.h>

int main(){
	int cnt;
	int A, B, V;

	scanf("%d %d %d", &A, &B, &V);
	cnt = V / (A - B);
	while (((A - B) * cnt + A) > V)
		cnt--;
	while (((A - B) * cnt + A) < V)
		cnt++;
	cnt++;
	printf("%d", cnt);
}