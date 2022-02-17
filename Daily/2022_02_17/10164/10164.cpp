#include <iostream>
#include <cstring>
using namespace std;

int directions[2][2] = {{0, -1}, {-1, 0}};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int table[16][16] = {0};
	int dp[16][16] = {0};
	int row, col, K;
	cin >> row >> col >> K;
	for(int i = 0; i < row * col; i++){
		table[i / col][i % col] = i + 1;
	}
	dp[0][0] = 1;
	int K_x, K_y;
	if (K != 0){
		K_x = (K - 1) / col;
		K_y = (K - 1) % col;
	}
	else{
		K_x = 0;
		K_y = 0;
	}
	for(int i = 0; i <= K_x; i++){
		for(int j = 0; j <= K_y; j++){
			for(int k = 0; k < 2; k++){
				int ni = i + directions[k][0];
				int nj = j + directions[k][1];
				if (ni >= 0 && ni < row && nj >= 0 && nj < col){
					dp[i][j] += dp[ni][nj];
				}
			}
		}
	}
	int tmp = dp[K_x][K_y];
	memset(dp, 0, sizeof(dp));
	dp[K_x][K_y] = 1;
	for(int i = K_x; i < row; i++){
		for(int j = K_y; j < col; j++){
			for(int k = 0; k < 2; k++){
				int ni = i + directions[k][0];
				int nj = j + directions[k][1];
				if (ni >= 0 && ni < row && nj >= 0 && nj < col){
					dp[i][j] += dp[ni][nj];
				}
			}
		}
	}
	cout << tmp * dp[row - 1][col - 1] << "\n";
}