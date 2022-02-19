#include <iostream>
#include <vector>
using namespace std;

void solve(){
	int cnt, num, won;
	cin >> cnt;
	vector <int> coins;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		coins.push_back(num);
	}
	int dp[10001] = {0};
	dp[0] = 1;
	cin >> won;
	for(int i = 0; i < cnt; i++){
		for(int j = coins[i]; j <= won; j++){
			dp[j] += dp[j - coins[i]];
		}
	}
	cout << dp[won] << "\n";

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test_case;
	cin >> test_case;
	while(test_case--){
		solve();
	}
}

/*
풀이보고 이해하는데 1시간
구현시간 4:22

*/