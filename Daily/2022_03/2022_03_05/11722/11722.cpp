#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int arr[1000];
	int dp[1000];
	int cnt, ret = 0;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> arr[i];
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if (arr[i] < arr[j]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ret = max(ret, dp[i]);
	}
	cout << ret << "\n";
}