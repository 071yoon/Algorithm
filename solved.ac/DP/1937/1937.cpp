#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int map[502][502];
int dp[502][502] = {0};
int N ,ret = 0;

int check(int y, int x){
	for(int i = 0; i < 4; i++){
		int new_y = y + dy[i];
		int new_x = x + dx[i];
		if (new_y > 0 && new_y <= N && new_x > 0 && new_x <= N){
			if (map[y][x] > map[new_y][new_x]){
				return (0);
			}
		}
	}
	return (1);
}

void dp_run(int y, int x){
	if (dp[y][x] == 0 && check(y, x)){
		dp[y][x] = 1;
	}
	else{
		for(int i = 0; i < 4; i++){
			int new_y = y + dy[i];
			int new_x = x + dx[i];
			int tmp = 0;
			if (new_y > 0 && new_y <= N && new_x > 0 && new_x <= N){
				if (map[y][x] > map[new_y][new_x]){
					if (dp[new_y][new_x] == 0)
						dp_run(new_y, new_x);
					dp[y][x] = max(dp[y][x], dp[new_y][new_x] + 1);
				}
			}
		}
	}
	ret = max(ret, dp[y][x]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++)
			cin >> map[i][j];
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			dp_run(i, j);
		}
	}
	/*
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}*/
	cout << ret << "\n";
}