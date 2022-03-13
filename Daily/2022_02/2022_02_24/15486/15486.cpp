#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1500000] = {0};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, take, price;
	cin >> cnt;
	int ret = 0;
	vector <pair<int, int> > vec;
	for(int i = 0; i < cnt; i++){
		cin >> take >> price;
		vec.push_back(make_pair(take, price));
	}
	for(int i = cnt - 1; i >= 0; i--){
		if ((vec[i].first + i) <= cnt){
			dp[i] = max(dp[i + 1], dp[vec[i].first + i] + vec[i].second);
		}
		else{
			dp[i] = dp[i + 1];
		}
	}
	cout << dp[0] << "\n";
}
/*
1  2  3  4  5  6  7
0  0  0  10 10 10 10
0  0  0  10 10 10 30
0  0  0  20 20 20 40
0  0  0  20 20 20 55

1  2  3  4  5  6  7  8  9  10
5  4  3  2  1  1  2  3  4  5
50 40 30 20 10 10 20 30 40 50

*/