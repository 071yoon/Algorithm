#include <iostream>
#include <algorithm>
using namespace std;

int dx[3] = {-1, -1, 0};
int dy[3] = {0, -1, -1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int col, row;
	cin >> col >> row;
	int arr[1000][1000] = {0};
	int dp[1000][1000] = {0};

	for(int y = 0; y < col; y++){
		for(int x = 0; x < row; x++){
			cin >> arr[y][x];
			dp[y][x] = arr[y][x];
			for(int k = 0; k < 3; k++){
				int new_x = x + dx[k];
				int new_y = y + dy[k];
				if (new_x >= 0 && new_x < row && new_y >= 0 && new_y < col){
					dp[y][x] = max(dp[y][x], dp[new_y][new_x] + arr[y][x]);
				}
			}
		}
	}
	cout << dp[col - 1][row - 1] << "\n";
}