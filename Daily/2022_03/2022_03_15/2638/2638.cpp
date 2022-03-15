#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int row, col;
int board[100][100] = {0};
int dir[4][2] ={{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool air[100][100] = {0};

void inputs(){
	cin >> row >> col;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> board[i][j];
		}
	}
}

bool is_air(int i, int j){
	queue <pair<int, int> > que;
	bool visited[100][100] = {0};
	que.push(make_pair(i, j));
	visited[i][j] = 1;
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		if (x == 0 || x == row - 1 || y == 0 || y == col - 1) return true;
		que.pop();
		for(int k = 0; k < 4; k++){
			int nx = x + dir[k][0];
			int ny = y + dir[k][1];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
			if (!visited[nx][ny] && board[nx][ny] == 0){
				visited[nx][ny] = 1;
				que.push(make_pair(nx,ny));
			}
		}
	}
	return false;
}

void fill_air(int i, int j){
	queue <pair<int, int> > que;
	bool visited[100][100] = {0};
	que.push(make_pair(i, j));
	air[i][j] = 1;
	visited[i][j] = 1;
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for(int k = 0; k < 4; k++){
			int nx = x + dir[k][0];
			int ny = y + dir[k][1];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
			if (!visited[nx][ny] && board[nx][ny] == 0){
				visited[nx][ny] = 1;
				air[nx][ny] = 1;
				que.push(make_pair(nx,ny));
			}
		}
	}
	return ;
}

void do_air(){
	memset(air, 0, sizeof(air));
	bool visited[100][100] = {0};
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (!board[i][j] && !air[i][j] && is_air(i, j)){
				fill_air(i, j);
			}
		}
	}
}

bool is_done(){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (board[i][j] == 1) return false;
		}
	}
	return true;
}

void cheese(){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (board[i][j]){
				int cnt = 0;
				for(int k = 0; k < 4; k++){
					int ni = i + dir[k][0];
					int nj = j + dir[k][1];
					if (air[ni][nj]) cnt++;
				}
				if (cnt >= 2){
					board[i][j] = 0;
				}
			}
		}
	}
}

void solve(){
	int tm = 0;
	while(1){
		if (is_done()){
			cout << tm << "\n";
			return ;
		}
		do_air();
		cheese();
		tm++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solve();
}