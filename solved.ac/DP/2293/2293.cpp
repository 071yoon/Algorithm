#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int coin[101] = {0};
	int dp[10001] = {0};
	int cnt, num;
	cin >> cnt >> num;
	for(int i = 0; i < cnt; i++){
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int i = 0; i < cnt; i++) {
		for (int j = coin[i]; j <= num; j++) { 
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[num] << "\n";
}