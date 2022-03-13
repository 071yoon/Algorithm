#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

char board[1000][1000] = {0};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int fire_board[1000][1000] = {0};
bool visited[1000][1000] = {0};

struct info{
	int x;
	int y;
	int cnt = 0;
};
queue <info> jihun;
queue <info> fire;
int row, col;

void inputs(){
	cin >> row >> col;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> board[i][j];
			if (board[i][j] == 'J'){
				info tmp; tmp.x = i; tmp.y = j;
				jihun.push(tmp);
			}
			else if (board[i][j] == 'F'){
				info tmp; tmp.x = i; tmp.y = j;
				fire.push(tmp);
			}
		}
	}
}

int solve(){
	memset(fire_board, -1, sizeof(fire_board));
	while(!fire.empty()){ //FIRE
		int x = fire.front().x;
		int y = fire.front().y;
		int cnt = fire.front().cnt;
		if (cnt == 0) fire_board[x][y] = 0;
		fire.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && fire_board[nx][ny] == -1 && board[nx][ny] != '#'){
				fire_board[nx][ny] = cnt + 1;
				info tmp; tmp.x = nx; tmp.y = ny; tmp.cnt = cnt + 1;
				fire.push(tmp);
			}
		}
	}
	// for(int i = 0; i < row; i++){
	// 	for(int j = 0; j < col; j++){
	// 		cout << fire_board[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	while(!jihun.empty()){
		int x = jihun.front().x;
		int y = jihun.front().y;
		int cnt = jihun.front().cnt;
		if (cnt == 0) visited[x][y] = 1;
		if (x == 0 || x == row - 1 || y == 0 || y == col - 1){
			return cnt + 1;
		}
		jihun.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && (fire_board[nx][ny] > cnt + 1 || fire_board[nx][ny] == -1)  && board[nx][ny] != '#' && !visited[nx][ny]){
				visited[nx][ny] = 1;
				info tmp; tmp.x = nx; tmp.y = ny; tmp.cnt = cnt + 1;
				jihun.push(tmp);
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	int ans = solve();
	if (ans == -1) cout << "IMPOSSIBLE\n";
	else cout << ans << "\n";
}