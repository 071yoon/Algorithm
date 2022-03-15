#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int sz;
int board[50][50] = {0};
int visited[50][50];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void inputs(){
	cin >> sz;
	string tmp;
	for(int i = 0; i < sz; i++){
		cin >> tmp;
		for(int j = 0; j < sz; j++){
			board[i][j] = tmp[j] - '0'; //1 -> white, 0 -> black
		}
	}
}

void solve(){
	memset(visited, -1, sizeof(visited));
	queue <pair<pair<int, int>, int> > que; // ( (x, y), cnt)
	que.push(make_pair(make_pair(0, 0), 0));
	while(!que.empty()){
		int x = que.front().first.first;
		int y = que.front().first.second;
		int cnt = que.front().second;
		que.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx < 0 || nx >= sz || ny < 0 || ny >= sz) continue;
			if (board[nx][ny] == 1 && (visited[nx][ny] == -1 || visited[nx][ny] > cnt)){ //white
				visited[nx][ny] = cnt;
				que.push(make_pair(make_pair(nx, ny), cnt));
			}
			else{ //black
				if (visited[nx][ny] == -1 || visited[nx][ny] > cnt + 1){
					visited[nx][ny] = cnt + 1;
					que.push(make_pair(make_pair(nx, ny), cnt + 1));
				}
			}
		}
	}
	cout << visited[sz - 1][sz - 1] << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solve();
}