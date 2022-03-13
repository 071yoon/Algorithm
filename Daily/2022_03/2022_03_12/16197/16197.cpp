#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row, col;
char mapp[20][20] = {0}; //1x1y2x2y
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool visited[20][20][20][20] = {0}; //1x1y2x2y

struct coin{
	int x;
	int y;
};
struct info{
	coin c1;
	coin c2;
	int cnt;
};

vector <coin> coins;

bool is_out(int x, int y){
	if (x >= 0 && x < row && y >= 0 && y < col) return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> mapp[i][j];
			if (mapp[i][j] == 'o'){
				coin c; c.x = i; c.y = j;
				coins.push_back(c);
			}
		}
	}
	int cnt = 0;
	info i; i.c1 = coins[0]; i.c2 = coins[1]; i.cnt = 0;
	queue <info> que;
	visited[coins[0].x][coins[0].y][coins[1].x][coins[1].y] = 1;
	que.push(i);
	while(!que.empty()){
		info cur = que.front();
		que.pop();
		if (cur.cnt >= 10){
			cout << "-1\n";
			return (0);
		}
		for(int i = 0 ; i < 4; i++){
			int nx1 = cur.c1.x + dir[i][0];
			int nx2 = cur.c2.x + dir[i][0];
			int ny1 = cur.c1.y + dir[i][1];
			int ny2 = cur.c2.y + dir[i][1];
			if ((is_out(nx1, ny1) && !is_out(nx2, ny2)) || (!is_out(nx1, ny1) && is_out(nx2, ny2))){
				cout << cur.cnt + 1 << "\n";
				return (0);
			}
			if (is_out(nx1, ny1) && is_out(nx2, ny2)) continue ;
			if (mapp[nx1][ny1] == '#' && mapp[nx2][ny2] == '#') continue ;
			if (mapp[nx1][ny1] == '#'){
				nx1 = cur.c1.x;
				ny1 = cur.c1.y;
			}
			else if (mapp[nx2][ny2] == '#'){
				nx2 = cur.c2.x;
				ny2 = cur.c2.y;
			}
			if (!visited[nx1][ny1][nx2][ny2]){
				visited[nx1][ny1][nx2][ny2] = 1;
				info in; in.c1.x = nx1; in.c1.y = ny1; in.c2.x = nx2; in.c2.y = ny2; in.cnt = cur.cnt + 1;
				que.push(in);
			}
		}
	}
	cout << "-1\n";
}