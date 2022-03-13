#define MOD 1000000009
#include <iostream>
using namespace std;

long long dp[100001][4] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num;
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][2] = 1; dp[3][1] = 1; dp[3][3] = 1;
	for(int i = 4; i <= 100000; i++){
		dp[i][1] = (dp[i - 1][2]  + dp[i - 1][3] ) % MOD;
		dp[i][2] = (dp[i - 2][3]  + dp[i - 2][1] ) % MOD;
		dp[i][3] = (dp[i - 3][1]  + dp[i - 3][2] ) % MOD;
	}
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		cout << (dp[num][1] + dp[num][2] + dp[num][3]) % MOD << "\n";
	}
	return (0);
}
/*
1:1 -> 1
2:1 -> 2
3:3 -> 2 + 1, 1 + 2, 3
4:3 -> 1 + 3, 3 + 1, 1 + 2 + 1
5:4 -> 1 + 3 + 1, 2 + 1 + 2, 2 + 3, 3 + 2
6:5 -> 1 + (dp[5] - 1),  2 + (0), 3 + (dp[3] - 1)
7:

*/