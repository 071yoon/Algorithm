#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int D, K, A;
	int dp[31][2] = {0};
	cin >> D >> K;
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	for(int i = 2; i < 30; i++){
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 2][1] + dp[i - 1][1];
	}
	int x = dp[D - 1][0];
	int y = dp[D - 1][1];
	for(int i = 1; i <= 100000; i++){
		//(K - x * i) / 5 == 정수
		if ((K - x * i) % y == 0){
			cout << i << "\n" << (K - x * i) / y << "\n";
			return (0);
		}
	}
}
/*
10mins 24sec
2, 7, 9, 16, 25, 41
3x + 5y = 41
x, y, x+y, x+2y, 2x+3y, 3x+5y, 5x+8y, 8x+13y
2, 26, 28, 
*/