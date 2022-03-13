#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int dp[1001] = {0};
	int arr[1000] = {0};
	int cnt, num;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> arr[i];
		dp[i] = 987654321;
	}
	dp[0] = 0;
	for(int i = 0; i < cnt; i++){
		for(int j = i + 1; j <= i + arr[i]; j++){
			if (j < cnt)
				dp[j] = min(dp[j], dp[i] + 1);
		}
	}
	if (dp[cnt - 1] == 987654321)
		cout << "-1\n";
	else
		cout << dp[cnt - 1] << "\n";
}
/*
1 2 0 1 3 2 1 5 4 2
0 1 2 2 3 4 4 4 5 5 5 5 5
            5 5 6 6
			  6 7 7 7 7 7 7

*/
