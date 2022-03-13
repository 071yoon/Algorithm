#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int dp[16] = { 0 };
	int pay[16] = { 0 };
	int time[16] = { 0 };
	int n;
	int ret = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i] >> pay[i];
		for (int j = 0; j < i; j++) {
			if ((time[j] + j <= i) && (i + time[i] <= n + 1)) {
				dp[i] = max(dp[i], dp[j] + pay[i]);
				ret = max(dp[i], ret);
			}
		}
	}
	cout << ret << "\n";
}