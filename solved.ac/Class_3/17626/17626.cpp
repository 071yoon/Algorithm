#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int dp[50001];
	int n;
	cin >> n;
	dp[1] = 1;
	for(int i = 1; i <= n; i++){
		dp[i] = 1 + dp[i - 1];
		for(int j = 2; j * j <= i; j++){
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}
	cout << dp[n] << "\n";
}
