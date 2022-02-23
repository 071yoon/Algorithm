#include <iostream>
#include <algorithm>
using namespace std;

int row, col, trash;
int school[100][100] = {0};
bool visited[100][100] = {0};
int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int x, int y, int *cnt){
	visited[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny] && school[nx][ny]){
			*cnt += 1;
			dfs(nx, ny, cnt);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col >> trash;
	for(int i = 0; i < trash; i++){
		int x, y;
		cin >> x >> y;
		school[x - 1][y - 1] = 1;
	}
	int ret = 0;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (school[i][j] && !visited[i][j]){
				int cnt = 1;
				dfs(i, j, &cnt);
				ret = max(ret, cnt);
			}
		}
	}
	cout << ret << "\n";
}