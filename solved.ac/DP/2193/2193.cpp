#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long dp[91];
	dp[1] = 1;
	dp[2] = 1;
	long long num;
	cin >> num;
	for(int i = 3; i <= num; i++)
		dp[i] = dp[i - 2] + dp[i - 1];
	cout << dp[num] << "\n";
}