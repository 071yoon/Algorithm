#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num;
	int box[1001] = {0};
	int dp[1001] = {0};
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> box[i];
	}
	dp[0] = 1;
	int ret = 0;
	for(int i = 1; i < cnt; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if (box[i] > box[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ret = max(dp[i], ret);
	}
	cout << ret << "\n";
}