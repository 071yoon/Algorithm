#include <iostream>
#include <algorithm>
using namespace std;

int min_dp[3][2] = {0};
int max_dp[3][2] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num;
	cin >> cnt;
	for(int i = 0; i < 3; i++){
		cin >> num;
		min_dp[i][0] = num;
		max_dp[i][0] = num;
	}
	for(int i = 1; i < cnt; i++){
		int now = 0;
		int before = 0;
		if (i % 2){
			now = 1;
			before = 0;
		}
		else{
			now = 0;
			before = 1;
		}
		for(int j = 0; j < 3; j++){
			cin >> num;
			if (j == 0){
				max_dp[j][now] = num + max(max_dp[j][before], max_dp[j + 1][before]);
				min_dp[j][now] = num + min(min_dp[j][before], min_dp[j + 1][before]);
			}
			else if (j == 2){
				max_dp[j][now] = num + max(max_dp[j - 1][before], max_dp[j][before]);
				min_dp[j][now] = num + min(min_dp[j - 1][before], min_dp[j][before]);
			}
			else{
				max_dp[j][now] = num + max(max_dp[j - 1][before], max(max_dp[j + 1][before], max_dp[j][before]));
				min_dp[j][now] = num + min(min_dp[j - 1][before], min(min_dp[j + 1][before], min_dp[j][before]));
			}
		}
	}
	int max_val = 0;
	int min_val = 987654321;
	for(int i = 0; i < 3; i++){
		max_val = max(max_val, max_dp[i][(cnt + 1) % 2]);
		min_val = min(min_val, min_dp[i][(cnt + 1) % 2]);
	}
	cout << max_val << " " << min_val << "\n";
}