#include <iostream>
#include <queue>
using namespace std;

bool visited[200][200][31] = {0}; //before jump, after jump
int mapp[200][200] = {0};
int jump, row, col;

int normal[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int horse[8][2] ={{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

struct info{
	int x;
	int y;
	int jump_cnt;
	int cnt;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> jump >> col >> row;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> mapp[i][j];
		}	
	}
	queue <info> que;
	info s; s.x = 0; s.y = 0; s.jump_cnt = 0; s.cnt = 0;
	visited[0][0][0] = 1;
	que.push(s);
	while(!que.empty()){
		int x = que.front().x;
		int y = que.front().y;
		int cnt = que.front().cnt;
		int jump_cnt = que.front().jump_cnt;
		if (x == row - 1 && y == col - 1){
			cout << cnt << "\n";
			return (0) ;
		}
		que.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + normal[i][0];
			int ny = y + normal[i][1];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny][jump_cnt] && !mapp[nx][ny]){
				visited[nx][ny][jump_cnt] = 1;
				info cur; cur.x = nx; cur.y = ny; cur.jump_cnt = jump_cnt; cur.cnt = cnt + 1;
				que.push(cur);
			}
		}
		if (jump_cnt < jump){
			for(int i = 0; i < 8; i++){
				int nx = x + horse[i][0];
				int ny = y + horse[i][1];
				if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny][jump_cnt + 1] && !mapp[nx][ny]){
					visited[nx][ny][jump_cnt + 1] = 1;
					info cur; cur.x = nx; cur.y = ny; cur.jump_cnt = jump_cnt + 1; cur.cnt = cnt + 1;
					que.push(cur);
				}
			}
		}
	}
	cout << "-1\n";
}