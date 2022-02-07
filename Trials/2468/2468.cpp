#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int original[101][101];
int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool visited[101][101] = {0};

void dfs(int height, int x, int y){
	visited[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int new_x = x + direction[i][0];
		int new_y = y + direction[i][1];
		if ((new_x >= 0 && new_x < N && new_y >= 0 && new_y < N ) && !visited[new_x][new_y] && original[new_x][new_y] > height){
			dfs(height, new_x, new_y);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int max_height = 0;
	for(int i = 0; i < N * N; i++){
		cin >> original[i / N][i % N];
		max_height = max(max_height, original[i / N][i % N]);
	}
	int ret = 1;
	for(int height = 1; height < max_height; height++){
		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		for(int index = 0; index < N * N; index++){
			if (!visited[index / N][index % N] && original[index / N][index % N] > height){
				dfs(height, index / N, index % N);
				cnt++;
			}
		}
		ret = max(ret, cnt);
	}
	cout << ret << "\n";
}		