#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int		row, col, sx, sy;
char	board[100][100] = {0};
int		dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int		visited[100][100] = {0};
vector 	<pair<int, int> > dest;
queue	<pair<int, int> > que;

void inputs(){
	cin >> col >> row;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> board[i][j];
			if (board[i][j] == 'C'){
				dest.push_back(make_pair(i, j));
			}
		}
	}
}

void straight(int x, int y){
	for(int i = 0; i < 4; i++){
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		while(nx >= 0 && nx < row && ny >= 0 && ny < col && board[nx][ny] != '*'){
			if (visited[nx][ny] == -1){
				visited[nx][ny] = visited[x][y] + 1;
				que.push(make_pair(nx, ny));
			}
			nx += dir[i][0];
			ny += dir[i][1];
		}
	}
}

void solve(){
	memset(visited, -1, sizeof(visited));
	que.push(make_pair(dest[0].first, dest[0].second));
	visited[dest[0].first][dest[0].second] = 0;
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		if (x == dest[1].first && y == dest[1].second){
			cout << visited[x][y] - 1 << "\n";
			return ;
		}
		straight(x, y);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solve();
}