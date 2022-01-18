#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int T, K;
int sum[501] = {0};
int file[501] = {0};
int dp[501][501] = {0};

int main(){
	cin >> T;

	while (T--){
		cin >> K;
		for (int i = 1; i <= K; i++){
			cin >> file[i];
			sum[i] = sum[i - 1] + file[i];
		}
		for (int inc = 1; inc <= K; inc++){
			for (int start = 1; start <= K - inc; start++){
				dp[start][inc + start] = INT_MAX;
				for (int end = start; end < inc + start; end++)
					dp[start][inc + start] = min(dp[start][inc + start], 
					dp[start][end] + dp[end + 1][inc + start] + sum[inc + start] - sum[start - 1]);
			}
		}
		cout << dp[1][K] << endl;
	}
}