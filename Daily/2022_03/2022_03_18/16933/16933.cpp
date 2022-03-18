#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int row, col, wall_cnt;
struct info{
	int x;
	int y;
	int wall;
	int day;
};
bool board[1000][1000] = {0};
bool visited[1000][1000][11] = {0};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void inputs(){
	string str;
	cin >> row >> col >> wall_cnt;
	for(int i = 0; i < row; i++){
		cin >> str;
		for(int j = 0; j < col; j++){
			board[i][j] = str[j] - '0';
		}
	}
}

void solution(){
	queue <info> que;
	info tmp; tmp.x = 0; tmp.y = 0; tmp.wall = 0; tmp.day = 1;
	que.push(tmp);
	while(!que.empty()){
		int x = que.front().x;
		int y = que.front().y;
		int wall = que.front().wall;
		int day = que.front().day;
		if (x == row - 1 && y == col - 1){
			cout << day << "\n";
			return ;
		}
		que.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			int nwall = wall + 1;
			int nday = day + 1;
			if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
			if (board[nx][ny] && !visited[nx][ny][nwall] && wall < wall_cnt){ //wall
				if (day % 2){ //day
					tmp.x = nx; tmp.y = ny; tmp.wall = nwall; tmp.day = nday;
					visited[nx][ny][nwall] = 1;
					que.push(tmp);
				}
				else{ //night
					tmp.x = x; tmp.y = y; tmp.wall = wall; tmp.day = nday;
					que.push(tmp);
				}
			}
			else if (board[nx][ny] == 0 && !visited[nx][ny][wall]){ //no wall
				tmp.x = nx; tmp.y = ny; tmp.wall = wall; tmp.day = nday;
				visited[nx][ny][wall] = 1;
				que.push(tmp);
			}
		}
	}
	cout << "-1\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solution();
}