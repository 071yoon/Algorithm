#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt;
	cin >> cnt;
	int dp[1001] = {0};
	vector <int> vec;
	for(int i = 0; i < cnt; i++){
		int num;
		cin >> num;
		vec.push_back(num);
		dp[i + 1] = vec[i];
		for(int j = 1; j <= (i + 1) / 2; j++){
			dp[i + 1] = min(dp[i + 1], dp[j] + dp[i + 1 - j]);
		}
	}
	cout << dp[cnt] << "\n";
}

/*
10
5  10 11 12 13 30 35 40 45 47
1  2  3  4  5  6  7  8  9  10
50 50 33 24 26 30 35 40 45 47
0  0  1  2  0  4  3  2  1  0

*/