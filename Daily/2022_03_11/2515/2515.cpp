#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector <pair<int, int> > pic;
vector <int> lim;
vector <int> dp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, len;
	cin >> cnt >> len;
	dp.resize(cnt + 1);
	lim.resize(cnt + 1);
	pic.resize(cnt + 1);
	pic[0] = make_pair(0, 0);
	for(int i = 1; i <= cnt; i++){
		int num, val;
		cin >> num >> val;
		pic[i] = make_pair(num, val);
	}
	sort(pic.begin(), pic.end());
	for(int i = 1; i <= cnt; i++){
		for(lim[i] = lim[i - 1]; lim[i] < i; lim[i]++){
			if (pic[i].first - pic[lim[i]].first < len) break ;
		}
		lim[i]--;
	}
	for(int i = 1; i <= cnt; i++){
		dp[i] = (max(dp[i - 1], dp[lim[i]] + pic[i].second));
	}
	cout << dp[cnt] << "\n";
}