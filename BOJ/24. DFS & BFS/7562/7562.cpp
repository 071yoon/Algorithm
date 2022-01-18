#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int cnt, len, dest_x, dest_y;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int visit[300][300];
queue <pair <int, pair<int, int> > > que;

int BFS(int x, int y){
	while (!que.empty()){
		int moves = que.front().first;
		int now_x = que.front().second.first;
		int now_y = que.front().second.second;
		que.pop();
		if (now_x == dest_x && now_y == dest_y)
			return (moves);
		for(int i = 0; i < 8; i++){
			int nx = now_x + dx[i];
			int ny = now_y + dy[i];
			if (nx >= 0 && nx < len && ny >=0 && ny < len && visit[nx][ny] == 0){
				que.push(make_pair(moves + 1, make_pair(nx, ny)));
				visit[nx][ny] = 1;
			}
		}
	}
	return (-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x, y;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		memset(visit, 0, sizeof(visit));
		cin >> len;
		cin >> x >> y;
		cin >> dest_x >> dest_y;
		visit[x][y] = 1;
		que.push(make_pair(0, make_pair(x, y)));
		cout << BFS(x, y) << "\n";
	}
}