#include <iostream>
#include <queue>

using namespace std;

int N, M, H, ret;
int tomato[101][101][101] = {0};
queue <pair <int, pair<int, int> > > tomato_que;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ret = 0;
	cin >> M >> N >> H;
	int dx[6] = {1, 0, -1, 0, 0, 0};
	int dy[6] = {0, 1, 0, -1, 0, 0};
	int dz[6] = {0, 0, 0, 0, -1, 1};
	for(int k = 0; k < H; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				cin >> tomato[k][i][j];
				if (tomato[k][i][j] == 1)
					tomato_que.push(make_pair(k, make_pair(i, j)));
			}
		}
	}
	while (!tomato_que.empty()){
		int que_sz = tomato_que.size();
		for(int i = 0; i < que_sz; i++){
			int z = tomato_que.front().first;
			int y = tomato_que.front().second.first;
			int x = tomato_que.front().second.second;
			tomato_que.pop();
			for(int dir = 0; dir < 6; dir++){
				int nz = z + dz[dir]; 
				int nx = y + dx[dir];
				int ny = x + dy[dir];
				if(nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
					continue;
				if(tomato[nz][nx][ny] == 1 || tomato[nz][nx][ny] == -1)
					continue;
				tomato[nz][nx][ny] = 1;
				tomato_que.push(make_pair(nz, make_pair(nx, ny)));
			}
		}
		ret++;
	}
	for(int k = 0; k < H; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if (tomato[k][i][j] == 0){
					cout << "-1";
					return (0);
				}
			}
		}
	}
	cout << ret - 1;
	return (0);
}