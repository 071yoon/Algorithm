#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cards[1001] = {0};
	int dp[1001] = {0};
	int num;
	cin >> num;
	for(int i = 1; i <= num; i++)
		cin >> cards[i];
	for(int i = 1; i <= num; i++){
		for(int j = 1; j <= i; j++){
			dp[i] = max(dp[i], dp[i - j] + cards[j]);
		}
	}
	cout << dp[num] << "\n";
}