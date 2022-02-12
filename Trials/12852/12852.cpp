#include <iostream>
using namespace std;

int before[1000001] = {0};
int dp[1000001] = {0};

void recur(int num){
	for(int i = 2; i <= num; i++){
		dp[i] = dp[i - 1] + 1;
		before[i] = i - 1;
		if (i % 3 == 0){
			if (dp[i] > dp[i / 3] + 1){
				dp[i] = dp[i / 3] + 1;
				before[i] = i / 3;
			}
		}
		if (i % 2 == 0){
			if (dp[i] > dp[i / 2] + 1){
				dp[i] = dp[i / 2] + 1;
				before[i] = i / 2;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt;
	cin >> cnt;
	recur(cnt);
	cout << dp[cnt] << "\n";
	while (cnt != 0){
		cout << cnt << " ";
		cnt = before[cnt];
	}
}