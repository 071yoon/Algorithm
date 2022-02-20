#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3][32] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int time, move, jadu;
	int ret = 1;
	cin >> time >> move;
	cin >> jadu;
	if (jadu == 2) dp[1][2][1] = 1; else dp[1][1][0] = 1;
	for(int i = 2; i <= time; i++){
		cin >> jadu;
		int jadu2;
		if (jadu == 2) jadu2 = 1; else jadu2 = 2;
		dp[i][jadu][0] = dp[i - 1][jadu][0] + 1;
		dp[i][jadu2][0] = dp[i - 1][jadu2][0];
		ret = max(ret, dp[i][jadu][0]);
		for(int j = 1; j <= move; j++){
			dp[i][jadu][j] = max(dp[i - 1][jadu][j] + 1, dp[i - 1][jadu2][j - 1] + 1);
			dp[i][jadu2][j] = max(dp[i - 1][jadu][j - 1], dp[i - 1][jadu2][j]);
			ret = max(ret, dp[i][jadu][j]);
		}
	}
	cout << ret << "\n";
}
/*
dp[시간][현재위치][이동횟수]
dp[1][1][0] = 0, dp[1][2][1] = 1
dp[2][1][0] = 1, dp[2][2][1] = 0, dp[2][1][2] = 2, dp[2][2][1] = 1


*/