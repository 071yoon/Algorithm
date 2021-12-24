#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector <int> dp;
	vector <int> arr;

	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++){
		int num;
		cin >> num;
		arr.push_back(num);
	}
	dp.push_back(arr[0]);
	dp.push_back(arr[0] + arr[1]);
	dp.push_back(max(arr[0] + arr[2], arr[1] + arr[2]));
	for(int i = 3; i < cnt; i++){
		dp.push_back(max(arr[i] + dp[i  - 2], arr[i] + arr[i - 1] + dp[i - 3]));
	}
	cout << dp[cnt - 1];
}