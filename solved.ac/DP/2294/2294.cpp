#include <iostream>
#include <climits>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, num;
	int coin[100];
	cin >> n >> k;
	int dp[10001] = {0};
	for(int i = 1; i <= k; i++){
		dp[i] = INT_MAX;
	}
	for(int i = 0; i < n; i++){
		cin >> coin[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = coin[i]; j <= k; j++){
			if (dp[j - coin[i]] != INT_MAX)
				dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[k] == INT_MAX)
		cout << "-1\n";
	else
		cout << dp[k] << "\n";
}


/*
#include <iostream>
#include <climits>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, num;
	cin >> n >> k;

	int	dp[100100] = {0};
	for(int i = 0; i < n; i++){
		cin >> num;
		dp[num] = 1;
	}
	for(int i = 1; i <= k; i++){
		if (dp[i] == 0)
			dp[i] = INT_MAX;
		for(int j = 1; j <= i / 2; j++){
			if (dp[j] == INT_MAX || dp[i - j] == INT_MAX)
				continue ;
			dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
	}
	if (dp[k] == INT_MAX)
		cout << "-1\n";
	else
		cout << dp[k] << "\n";
}
*/