#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K, num1, num2, num3, num4;
int graph[100][100] = {0};
bool visited[100][100] = {0};
int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector <int> ret;

void dfs(int x, int y, int *test_cnt){
	*test_cnt += 1;
	visited[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && graph[nx][ny] == 0){
			dfs(nx, ny, test_cnt);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N >> K;
	for(int i = 0; i < K; i++){
		cin >> num1 >> num2 >> num3 >> num4;
		for(int j = num1; j < num3; j++){
			for(int i = num2; i < num4; i++){
				graph[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if (!visited[i][j] && graph[i][j] == 0){
				int test_cnt = 0;
				cnt++;
				dfs(i, j, &test_cnt);
				ret.push_back(test_cnt);
			}
		}
	}
	cout << cnt << "\n";
	sort(ret.begin(), ret.end());
	for(int i = 0; i < ret.size(); i++){
		cout << ret[i] << " ";
	}
}