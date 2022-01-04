#include <iostream>
#include <queue>

using namespace std;

int N, M, ret;
int tomato[1001][1001] = {0};
queue <pair<int, int> > tomato_que;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ret = 0;
	cin >> M >> N;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
				tomato_que.push(make_pair(i, j));
		}
	}
	while (!tomato_que.empty()){
		int que_sz = tomato_que.size();
		for(int i = 0; i < que_sz; i++){
			int y = tomato_que.front().first;
			int x = tomato_que.front().second;
			tomato_que.pop();
			for(int dir = 0; dir < 4; dir++){ 
				int nx = y + dx[dir];
				int ny = x + dy[dir];
				if(nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;
				if(tomato[nx][ny] == 1 || tomato[nx][ny] == -1)
					continue;
				tomato[nx][ny] = 1;
				tomato_que.push(make_pair(nx, ny));
			}
		}
		ret++;
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if (tomato[i][j] == 0){
				cout << -1;
				return (0);
			}
		}
	}
	cout << ret - 1;
	return (0);
}