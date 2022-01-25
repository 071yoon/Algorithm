#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num;
	cin >> num;
	int dp[31] = {0};
	dp[0] = 1;
	dp[2] = 3;
	for(int i = 4; i <= num; i += 2){
		dp[i] = dp[i - 2] * 3;
		for(int j = 4; j <= i; j += 2){
			dp[i] += dp[i - j] * 2;
		}
	}
	cout << dp[num] << "\n";
}


