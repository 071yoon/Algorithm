#include <algorithm>
#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int dp[101][10];
	int cnt;
	cin >> cnt;
	for(int i = 0; i < 10; i++){
		dp[1][i] = 1;
	}
	for(int i = 2; i <= cnt; i++){
		for(int j = 0; j < 10; j++){
			if (j == 0){
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9){
				dp[i][j] = dp[i - 1][j - 1];
			}
			else{
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % 1000000000;
			}
		}
	}
	int sum = 0;
	for(int i = 1; i < 10; i++){
		sum = (sum + dp[cnt][i]) % 1000000000;
	}		
	cout << sum % 1000000000;
}