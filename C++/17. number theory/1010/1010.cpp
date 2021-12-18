#include <stdio.h>

int main(){
	int n, k, cnt;

	scanf("%d", &cnt);
	long long answer = 1;
	for (int t = 0; t < cnt; t++){
		scanf("%d %d", &n, &k);
		if (n > (k / 2))
			n = k - n;
		for (int j = 0; j < n; j++)
			answer *= (k - j);
		for (int i=0; i < n; i++)
			answer /= i+1;
		printf("%lld\n", answer);
	}
}