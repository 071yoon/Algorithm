#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int dp[1001] = {0};
	int arr[1001] = {0};
	int cnt, num;
	cin >> cnt;
	for (int i = 0; i < cnt; i++){
		cin >> num;
		arr[i] = num;
	}
	int tot_max = 0;
	for (int i = 0; i < cnt; i++){
		int max = 0;
		for(int j = 0; j < i; j++){
			if (arr[i] > arr[j]){
				if (max < dp[j]){
					max = dp[j];
				}
			}
		}
		dp[i] = max + 1;
		if (dp[i] > tot_max)
			tot_max = dp[i];
	}
	cout << tot_max;
}