#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

char land[50][50];
int visited[50][50] = {0};
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int garo, sero, answer = 0;

void bfs(queue <pair<pair<int, int>, int> > &que){ //que index and counter
	while(!que.empty()){
		int x = que.front().first.first;
		int y = que.front().first.second;
		int counter = que.front().second;
		que.pop();
		answer = max(answer, counter);
		for(int i = 0; i < 4; i++){
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (nx >= 0 && nx < garo && ny >= 0 && ny < sero && !visited[nx][ny] && land[nx][ny] == 'L'){
				visited[nx][ny] = 1;
				que.push(make_pair(make_pair(nx, ny), counter + 1));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> garo >> sero;
	for(int i = 0; i < garo * sero; i++){
		cin >> land[i / sero][i % sero];
	}
	for(int i = 0; i < garo * sero; i++){
		memset(visited, 0, sizeof(visited));
		queue <pair<pair<int, int>, int> > que;
		if (land[i / sero][i % sero] == 'L'){
			visited[i / sero][i % sero] = 1;
			que.push(make_pair(make_pair(i / sero, i % sero), 0));
			bfs(que);
		}
	}
	cout << answer << "\n";
}