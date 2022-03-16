#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int row, col, limit;
int board[100][100] = {0};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int visited[100][100];

void inputs(){
	cin >> row >> col >> limit;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> board[i][j];
		}
	}
}

void solve(){
	memset(visited, -1, sizeof(visited));
	queue <pair<int, int> > que; //x and y
	que.push(make_pair(0, 0));
	int no_sword = 987654321;
	int sword = 987654321;
	visited[0][0] = 0;
	while (!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		if (x == row - 1 && y == col - 1){
			no_sword = visited[x][y];
			break ;
		}
		if (board[x][y] == 2){
			sword = visited[x][y] + abs(x - (row - 1)) + abs(y - (col - 1));
			continue;
		}
		for(int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue ;
			if ((board[nx][ny] == 0 || board[nx][ny] == 2) && visited[nx][ny] == -1){
				visited[nx][ny] = visited[x][y] + 1;
				que.push(make_pair(nx, ny));
			}
		}
	}
	if (sword > limit && no_sword > limit){
		cout << "Fail\n";
	}
	else{
		cout << min(sword, no_sword) << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solve();
}