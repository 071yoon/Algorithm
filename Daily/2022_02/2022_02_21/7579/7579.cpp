#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int dp[101][10001] = {0};
	int N, M, num;
	cin >> N >> M;
	vector <pair<int, int> > vec;
	for(int i = 0; i < N; i++){
		cin >> num;
		vec.push_back(make_pair(num, 0));
	}
	int sum = 0;
	for(int i = 0; i < N; i++){
		cin >> num;
		vec[i].second = num;
		sum += num;
	}

	for(int j = 0; j <= sum; j++){
		if (j >= vec[0].second)
			dp[0][j] = vec[0].first;
	}
	for(int i = 1; i < N; i++){
		for(int j = 0; j <= sum; j++){
			if (j - vec[i].second >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vec[i].second] + vec[i].first);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	for(int j = 0; j <= sum; j++){
		if (dp[N - 1][j] >= M){
			cout << j << "\n";
			return (0);
		}
	}
}
/*
30 10 20 35 40
3  0  3  5  4

A     0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
30,3  0  0  0  30 30 30 30 30 30 30 30 30 30 30 30 30
10,0  10 10 10 40 40 40 40 40 40 40 40 40 40 40 40 40
20,3  10 10 10 40 40 40 60 60 60 60 60 60 60 60 60 60
35,5  10 10 10 40 40 45 60 60 75 75 75 95 95 95 95 95
40,4  10 10 10 40 50 50 60 80 80 85 100100115115115135   

*/