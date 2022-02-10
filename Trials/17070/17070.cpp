#include <iostream>
using namespace std;

int map_sz, ret = 0;
int house[16][16] = {0};
bool visited[16][16] = {0};
int direction[3][2] = {{0, 1}, {1, 1}, {1, 0}};
void dfs(int x, int y, int dir);

void dfs_helper(int x, int y, int i){
	int nx = x + direction[i][0];
	int ny = y + direction[i][1];
	if (nx >= 0 && nx < map_sz && ny >= 0 && ny < map_sz && !visited[nx][ny] && house[nx][ny] == 0){
		if (i == 1){
			if (house[nx - 1][ny] == 0 && house[nx][ny - 1] == 0){
				visited[nx][ny] = 1;
				dfs(nx, ny, i);
				visited[nx][ny] = 0;
			}
		}
		else{
			visited[nx][ny] = 1;
			dfs(nx, ny, i);
			visited[nx][ny] = 0;
		}
	}
}

void dfs(int x, int y, int dir){
	if (x == map_sz - 1 && y == map_sz - 1){
		ret++;
		return ;
	}
	if (dir == 0){
		for(int i = 0; i < 2; i++){
			dfs_helper(x, y, i);
		}
	}
	else if (dir == 1){
		for(int i = 0; i < 3; i++){
			dfs_helper(x, y, i);
		}
	}
	else{
		for(int i = 1; i < 3; i++){
			dfs_helper(x, y, i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> map_sz;
	for(int i = 0; i < map_sz * map_sz; i++)
		cin >> house[i / map_sz][i % map_sz];
	visited[0][0] = 1;
	visited[0][1] = 1;
	dfs(0, 1, 0);
	cout << ret << "\n";
}