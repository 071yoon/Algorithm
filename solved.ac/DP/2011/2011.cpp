#include <iostream>
#include <algorithm>
#include <string>
# define mod 1000000
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	long long dp[5001] = {0};
	cin >> str;
	str = "0" + str;
	dp[0] = 1;

	for (int i = 1; i <= str.size(); i++) {
		int num = str[i] - '0';
		if (num > 0 && num <= 9) {
			dp[i] += dp[i - 1]; 
			dp[i] %= mod;
		}
		
		num = (str[i - 1] - '0') * 10 + (str[i] - '0');
		if (num >= 10 && num <= 26) {
			dp[i] += dp[i - 2];
			dp[i] %= mod;
		}
	}
	cout << dp[str.size() - 1] << "\n";
	return 0;
}