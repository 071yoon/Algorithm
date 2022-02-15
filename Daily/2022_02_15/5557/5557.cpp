#include <iostream>
using namespace std;

int arr[100] = {0};
long long dp[100][21] = {0};
long long ret = 0;
int cnt, num;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> arr[i];
	}
	dp[0][arr[0]] = 1;
	for(int i = 0; i < cnt - 2; i++){
		for(int j = 0; j < 21; j++){
			if (dp[i][j] > 0 && j + arr[i + 1] <= 20){
				dp[i + 1][j + arr[i + 1]] += dp[i][j];
			}
			if (dp[i][j] > 0 && j - arr[i + 1] >= 0){
				dp[i + 1][j - arr[i + 1]] += dp[i][j];
			}
		}
	}
	cout <<  dp[cnt - 2][arr[cnt - 1]] << "\n";
}

/*
3
1 3 4
8  3  2  4  8  7  2  4  0  8  8
8  11 13 17
         9
      9  13
	     5
   5  7  11
         3
      3  7
*/