#include <stdio.h>

int main(){
	int n, k;
	int dp[1001][1001] = {0};

	scanf("%d %d", &n, &k);
	dp[1][1] = 1;
	dp[1][0] = 1;
	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= k; j++){
			if (j == 0 || i == j)
				dp[i][j] = 1;
			else{
				dp[i][j] = dp[i - 1][j - 1] % 10007 + dp[i - 1][j] % 10007;
			}
		}
	}
	printf("%d", dp[n][k] % 10007);
}