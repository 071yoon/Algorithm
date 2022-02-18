#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int row, col, max_val = 0, ret = 0;
int painting[500][500] = {0};
bool visited[500][500] = {0};
int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y, int *cnt){
	for(int i = 0; i < 4; i++){
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny] && painting[nx][ny] == 1){
			visited[nx][ny] = 1;
			*cnt += 1;
			dfs(nx, ny, cnt);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> painting[i][j];
		}
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (painting[i][j] == 1 && !visited[i][j]){
				ret++;
				visited[i][j] = 1;
				int tmp = 1;
				dfs(i, j, &tmp);
				max_val = max(max_val, tmp);
			}
		}
	}
	cout << ret << "\n" << max_val << "\n";
}

//8 mins