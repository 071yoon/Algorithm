#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector <pair<int, int> > dp;
	dp.push_back(make_pair(1, 0));
	int cnt;
	cin >> cnt;
	for(int i = 1; i <= cnt; i++)
		dp.push_back(make_pair(dp[i - 1].second, dp[i - 1].first + dp[i - 1].second));
	cout << dp[cnt].first << " " << dp[cnt].second << "\n";
}