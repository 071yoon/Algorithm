#include <iostream>
#include <algorithm>
using namespace std;

string dp[101][101];

string adder(string a, string b){
	int sum = 0;
	string ret = "";
	while(!a.empty() || !b.empty() || sum){
		if (!a.empty()){
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()){
			sum += b.back() - '0';
			b.pop_back();
		}
		ret += (sum % 10 + '0');
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string solve(int n, int r){
	if (n == r || r == 0){
		return ("1");
	}
	string &ret = dp[n][r];
	if (ret != "") return ret;
	ret = adder(solve(n - 1, r - 1), solve(n - 1, r));
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, r;
	cin >> n >> r;
	cout << solve(n, r) << "\n";
}