#include <iostream>
using namespace std;

long long dp[31][31] = {0};

long long search(int one, int half){
	if (one < 0 || half < 0) return (0);
	if (dp[one][half]) return dp[one][half];
	if (one == 0 && half == 0) return 1;
	if (one > 0) dp[one][half] += search(one - 1, half + 1);
	if (half > 0) dp[one][half] += search(one, half - 1);
	return dp[one][half];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num;
	while (1){
		cin >> num;
		if (num == 0) break ;
		cout << search(num, 0) << "\n";
	}
}