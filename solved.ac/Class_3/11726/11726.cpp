#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int dp[10001];
	int num;
	cin >> num;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i = 4; i <= num; i++){
		dp[i] = (dp[i - 1]+ dp[i - 2]) % 10007;
	}	
	cout << dp[num];
}