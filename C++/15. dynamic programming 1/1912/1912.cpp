#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long dp[100001];
	vector <int> vec;
	int cnt, num;
	cin >> cnt;
	for (int i = 0; i < cnt; i++){
		cin >> num;
		vec.push_back(num);
	}
	dp[0] = vec[0];
	for (int i = 1; i < cnt; i++){
		if (dp[i - 1] > 0 ){
			dp[i] = dp[i - 1] + vec[i];
		}
		else{
			dp[i] = vec[i];
		}
	}
	cout << *max_element(dp, dp + cnt);
}