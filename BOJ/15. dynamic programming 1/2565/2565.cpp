#include <iostream>
#include <vector>
#include <utility>
#include <functional>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long dp[501] = {0};
	vector <pair<int,int> > arr;
	int cnt, num1, num2;

	cin >> cnt;
	for (int i = 0; i < cnt; i++){
		cin >> num1 >> num2;
		arr.push_back(make_pair(num1, num2));
	}
	sort(arr.begin(), arr.end());
	
	for(int i = 0; i < cnt; i++){
		int max = 0;
		for(int j = 0; j < i; j++){
			if (arr[i].second > arr[j].second && max < dp[j])
				max = dp[j];
		}
		dp[i] = max + 1;
	}
//	cout << dp[5];
	cout << cnt - *max_element(dp, dp + cnt);

}	