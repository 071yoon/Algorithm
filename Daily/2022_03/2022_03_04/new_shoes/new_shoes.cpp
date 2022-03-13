#include <iostream>
using namespace std;

int directions[2][2] = {{0, 1}, {1, 0}};
int mapp[100][100] = {0};
int ret = 0;
int cnt;

void dfs(int x, int y){
	if (x == cnt - 1 && y == cnt - 1){
		ret++;
		return ;
	}
	for(int i = 0; i < 2; i++){
		int nx = x + mapp[x][y] * directions[i][0];
		int ny = y + mapp[x][y] * directions[i][1];
		if (nx >= 0 && nx < cnt && ny >= 0 && ny < cnt ){
			dfs(nx, ny);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < cnt; j++){
			cin >> mapp[i][j];
		}
	}
	dfs(0, 0);
	cout << ret << "\n";
}