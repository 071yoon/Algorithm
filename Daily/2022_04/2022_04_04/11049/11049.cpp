#include <iostream>
#include <algorithm>
using namespace std;

int N, row, col;
int sum[501], matrix[501][2], dp[501][501];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> row >> col;
		matrix[i][0] = row;
		matrix[i][1] = col;
	}
	for(int i = 1; i < N; i++){
		for(int j = 1; i + j <= N; j++){
			dp[j][i + j] = 1000000000;
			for(int k = j; k <= i + j; k++){
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i+j][1]);
				//dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
			}
		}
	}
	cout << dp[1][N] << "\n";
}