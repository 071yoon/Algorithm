#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for(int loop = 0; loop < 3; loop++){
		int cnt, kind, num, total = 0;
		pair<int, int> coins[101];
		cin >> cnt;
		for(int i = 0; i < cnt; i++){
			cin >> kind >> num;
			coins[i] = make_pair(kind, num);
			total += (kind * num);
		}
		if (total % 2){
			cout << "0\n";
			continue ;
		}
		int dp[50001] = {0};
		dp[0] = 1;
		for(int i = 0; i < cnt; i++){
			for(int k = total / 2; k >= 0; k--){
				if (k - coins[i].first >= 0 && dp[k - coins[i].first]){
					for(int j = 0; j < coins[i].second; j++){
						if (k + j * coins[i].first <= total / 2) dp[k + j * coins[i].first] = 1;
					}
				}
			}
		}
		cout << dp[total / 2] << "\n";
	}
}