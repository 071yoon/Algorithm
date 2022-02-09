#include <iostream>
#include <algorithm>
using namespace std;

long long dp[100001] = {0};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i = 4; i <= 100000; i++){
		dp[i] = i;
		for(int j = 0; j * j <= i; j++){
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}
	int num;
	cin >> num;
	cout << dp[num] << "\n";
}