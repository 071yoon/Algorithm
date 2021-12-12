#include <stdio.h>

int main(){
	int n, k, cnt;

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		long long dp[31][31] = {0};
		scanf("%d %d", &n, &k);
		dp[1][1] = 1;
		dp[1][0] = 1;
		for (int i = 2; i <= n; i++){
			for (int j = 0; j <= k; j++){
				if (j == 0 || i == j)
					dp[i][j] = 1;
				else{
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				}
			}
		}
		if (n == 1)
			printf("%d\n", k);
		else
			printf("%lld\n", dp[n][k]);
	}
}