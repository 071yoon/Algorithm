#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int row, col, blocks;
bool board[1000][1000] = {0};
int visited[1000][1000][10] = {0};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
struct info{
	int x;
	int y;
	int cnt;
	int block;
};

void inputs(){
	cin >> row >> col >> blocks;
	string str;
	for(int i = 0; i < row; i++){
		cin >> str;
		for(int j = 0; j < col; j++){
			board[i][j] = str[j] - '0';
		}
	}
}

void solve(){
	info init; init.x = 0; init.y = 0; init.cnt = 1; init.block = 0;
	queue <info> que;
	visited[0][0][0] = 1;
	que.push(init);
	while(!que.empty()){
		int x = que.front().x;
		int y = que.front().y;
		int block = que.front().block;
		int cnt = que.front().cnt;
		que.pop();
		if (x == row - 1 && y == col - 1){
			cout << cnt << "\n";
			return ;
		}
		for(int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue ;
			if (board[nx][ny] && block < blocks && !visited[nx][ny][block + 1]){
				visited[nx][ny][block + 1] = 1;
				info tmp; tmp.x = nx; tmp.y = ny; tmp.cnt = cnt + 1; tmp.block = block + 1;
				que.push(tmp);
			}
			if (!board[nx][ny] && !visited[nx][ny][block]){
				visited[nx][ny][block] = 1;
				info tmp; tmp.x = nx; tmp.y = ny; tmp.cnt = cnt + 1; tmp.block = block;
				que.push(tmp);
			}
		}
	}
	cout << "-1\n";
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solve();
}