#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int directions[3][2] = {{0, -1}, {-1, -1}, {-1, 0}};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int total_map[1001][1001] = {0};
	int dp[1001][1001] = {0};
	int ret = 0;
	int row, col;
	string str;
	cin >> row >> col;
	for(int i = 1; i <= row; i++){
		cin >> str;
		for(int j = 1; j <= col; j++){
			total_map[i][j] = str[j - 1];
			if (total_map[i][j] == '0'){
				dp[i][j] = 0;
				continue ;
			}
			int new_nums[3] = {1, 1, 1};
			for(int k = 0; k < 3; k++){
				int new_i = i + directions[k][0];
				int new_j = j + directions[k][1];
				if (new_i < 1 || new_i > row || new_j < 1 || new_j > col){
					continue ;
				}
				else
					new_nums[k] = dp[new_i][new_j] + 1;
			}
			dp[i][j] = min(new_nums[1], min(new_nums[0], new_nums[2]));
			ret = max(dp[i][j], ret);
		}
	}
	cout << ret * ret << "\n";
}