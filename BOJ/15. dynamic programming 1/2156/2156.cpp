#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector <int> arr;
	vector <int> dp;
	int cnt;
	int num;
	cin >> cnt;
	for(int loop = 0; loop < cnt; loop++){
		cin >> num;
		arr.push_back(num);
	}
	dp.push_back(arr[0]);//dp[0]
	if (cnt >= 2)
		dp.push_back(arr[0] + arr[1]);//dp[1]
	for(int i = 2; i < cnt; i++){
		dp.push_back(max(dp[i - 1], max(dp[i - 2] + arr[i], arr[i] + arr[i - 1] + dp[i - 3])));//dp[i]

	}
//	cout << max(max(dp[cnt - 1], dp[cnt - 2]), dp[cnt - 3]);
	cout << *max_element(dp.begin(), dp.end());

}