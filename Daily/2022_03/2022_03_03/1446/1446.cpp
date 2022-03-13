#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, len;
	cin >> cnt >> len;
	for(int i = 0; i <= len; i++){
		dp[i] = i;
	}
	for(int i = 0; i < cnt; i++){
		int start, ender, cost;
		cin >> start >> ender >> cost;
		if (ender > len) continue ;
		if (dp[start] + cost < dp[ender]){
			dp[ender] = dp[start] + cost;
			for(int j = 0; j <= len; j++){
				if (j == 0) dp[j] = 0;
				dp[j] = min(dp[j], dp[j - 1] + 1);
			}
		}
	}
	for(int i = 0; i <= len; i++){
		cout << i << ":" << dp[i] << "\n";
	}
	cout << dp[len] << "\n";
}