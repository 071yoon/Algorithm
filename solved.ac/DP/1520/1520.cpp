#include <iostream>
#include <cstring>
using namespace std;

int arr[500][500];
int dp[500][500];
int col, row;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int y, int x){
	if (y == (col - 1) && x == (row - 1)){
		return 1;
	}
	if (dp[y][x] != -1)
		return (dp[y][x]);
	dp[y][x] = 0;
	for(int i = 0; i < 4; i++){
		int now_y = y + dy[i];
		int now_x = x + dx[i];
		if (now_y < col && now_y >= 0 && now_x < row && now_x >= 0){
			if (arr[now_y][now_x] < arr[y][x]){
				dp[y][x] += dfs(now_y, now_x);
			}
		}
	}
	return (dp[y][x]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> col >> row;
	for(int i = 0; i < col; i++){
		for(int j = 0; j < row; j++)
			cin >> arr[i][j];
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << "\n";
}