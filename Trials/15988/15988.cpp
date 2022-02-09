#include <iostream>
using namespace std;

long long dp[1000001] = {0};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num;
	cin >> cnt;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while(cnt--){
		cin >> num;
		for(int i = 4; i <= num; i++){
			if (dp[i] == 0)
				dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
		}
		cout << dp[num] << "\n";
	}
}