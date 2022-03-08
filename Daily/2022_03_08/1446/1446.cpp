#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[10001] = {0};
vector <pair<pair<int, int>, int> > vec;

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
		vec.push_back(make_pair(make_pair(start, ender), cost));
	}
	sort(vec.begin(), vec.end());
	for(int i = 0; i < cnt; i++){
		int start = vec[i].first.first;
		int ender = vec[i].first.second;
		int cost = vec[i].second;
		if (ender > len) continue ;
		if (dp[start] + cost < dp[ender]){
			dp[ender] = dp[start] + cost;
			for(int j = 0; j <= len; j++){
				if (j == 0) dp[j] = 0;
				dp[j] = min(dp[j], dp[j - 1] + 1);
			}
		}
	}
	cout << dp[len] << "\n";
}