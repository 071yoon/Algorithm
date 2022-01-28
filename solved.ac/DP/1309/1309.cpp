#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num;
	cin >> num;
	vector <int> dp;
	dp.push_back(1);
	dp.push_back(3);
	for(int i = 2; i <= num; i++){
		int tmp = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
		dp.push_back(tmp);
	}
	cout << dp[num] << "\n";
}