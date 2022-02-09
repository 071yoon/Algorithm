#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K, weight, value;
	cin >> N >> K;
	int ret = 0;
	
	for(int i = 1; i <= N; i++){
		cin >> weight >> value;
		for (int j = 1; j <= K; j++){
			dp[i][j] = dp[i - 1][j];
			if (j >= weight){
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
			}
			ret = max(dp[i][j], ret);
		}
	}
	cout << ret << "\n";
}