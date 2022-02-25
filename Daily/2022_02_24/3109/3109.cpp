#include <string>
#include <iostream>
using namespace std;

int row, col, num;
bool visited[10000][500] = {0};
int bread[10000][500] = {0};
int directions[3][2] = {{-1, 1}, {0, 1}, {1, 1}};
int ans = 0, ret = 0;

void dfs(int x, int y){
	visited[x][y] = 1;
	if (y == col - 1){
		ret = 1;
		ans++;
		return ;
	}
	for(int i = 0; i < 3; i++){
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny] && bread[nx][ny] == '.'){
			dfs(nx, ny);
			if (ret)
				return ;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col;
	for(int i = 0; i < row; i++){
		string str;
		cin >> str;
		for(int j = 0; j < col; j++){
			bread[i][j] = str[j];
		}
	}
	for(int i = 0; i < row; i++){
		if (bread[i][0] == '.'){
			ret = 0;
			dfs(i, 0);
		}
	}
	cout << ans << "\n";
}