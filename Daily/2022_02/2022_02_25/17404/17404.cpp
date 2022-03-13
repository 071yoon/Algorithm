#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int colors[1000][3] = {0};
	int dp[1000][3] = {0};

	int cnt;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
	}
	int ret = 987654321;
	for(int RGB = 0; RGB < 3; RGB++){
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 987654321; dp[0][1] = 987654321; dp[0][2] = 987654321;
		dp[0][RGB] = colors[0][RGB];
		for(int i = 1; i < cnt - 1; i++){
			dp[i][0] = colors[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = colors[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = colors[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}
		for(int i = 0; i < 3; i++){
			if (RGB == i){
				continue ;
			}
			else{
				if (i == 0)
					ret = min(ret, colors[cnt - 1][i] + min(dp[cnt - 2][1], dp[cnt - 2][2]));
				else if (i == 1)
					ret = min(ret, colors[cnt - 1][i] + min(dp[cnt - 2][0], dp[cnt - 2][2]));
				else
					ret = min(ret, colors[cnt - 1][i] + min(dp[cnt - 2][1], dp[cnt - 2][0]));
			}
		}
	}
	cout << ret << "\n";

}