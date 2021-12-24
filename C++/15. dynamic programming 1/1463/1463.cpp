#include <algorithm>
#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num;
	cin >> num;
	
	long long dp[1000001] = {0};
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= num; i++){
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0){
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0){
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}
	
	cout << dp[num];
}