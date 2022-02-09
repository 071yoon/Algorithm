#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int direction[8][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
int island[50][50] = {0};
int visited[50][50] = {0};
int N, M;

void dfs(int x, int y){
	visited[x][y] = 1;
	for(int i = 0; i < 8; i++){
		int new_x = x + direction[i][0];
		int new_y = y + direction[i][1];
		if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && island[new_x][new_y] == 1 && visited[new_x][new_y] == 0){
			dfs(new_x, new_y);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (1){
		cin >> M >> N;
		if (!N && !M)
			break ;
		memset(island, 0, sizeof(island));
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				cin >> island[i][j];
			}
		}
		int cnt = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if (island[i][j] == 1 && visited[i][j] == 0){
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << "\n";
	}
}