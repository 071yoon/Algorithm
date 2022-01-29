#include <iostream>
using namespace std;

long long dp[201][201] = {0};

long long sum(int K_this, int N_this){
	long long sum = 0;
	for(int i = 0; i <= N_this; i++){
		sum += dp[K_this - 1][i];
	}
	return (sum);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	for(int i = 0; i <= N; i++){
		dp[1][i] = 1;
	}
	for(int i = 2; i <= K; i++){
		for(int j = 0; j <= N; j++){
			dp[i][j] = sum(i, j) % 1000000000;
		}
	}
	cout << dp[K][N] % 1000000000 << "\n";
}