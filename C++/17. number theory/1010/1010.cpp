#include <stdio.h>

int main(){
	int n, k, cnt;

	scanf("%d", &cnt);
	for (int t = 0; t < cnt; t++){
		long long answer = 1;
		scanf("%d %d", &n, &k);
		int r = 1;
		for (int i = k; i > k - n; i--){
			answer *= i;
			answer /= r++;
		}
		printf("%lld\n", answer);
	}
}