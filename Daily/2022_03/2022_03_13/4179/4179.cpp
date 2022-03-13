#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char board[1000][1000] = {0};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
struct info{
	vector <pair<int, int> > jihun;
	vector <pair<int, int> > fire;
	int cnt = 0;
};
queue <info> que;
int row, col;

void print(){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

void inputs(info *init){
	cin >> row >> col;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> board[i][j];
			if (board[i][j] == 'J') init->jihun.push_back(make_pair(i, j));
			if (board[i][j] == 'F') init->fire.push_back(make_pair(i, j));
		}
	}
}

int spread(info *init){
	que.push(*init);
	while(!que.empty()){
		info tmp = que.front();
		for(int i = 0; i < tmp.jihun.size(); i++){
			if (tmp.jihun[i].first == row - 1 || tmp.jihun[i].second == col - 1 || tmp.jihun[i].first == 0 || tmp.jihun[i].second == 0){
				cout << tmp.jihun[i].first << ":" << tmp.jihun[i].second << "\n";
				return (tmp.cnt + 1);
			}
		}
		que.pop();
		info next; next.cnt = tmp.cnt + 1;
		for(int i = 0; i < tmp.jihun.size(); i++){ //jihun escape
			for(int j = 0; j < 4; j++){
				int nx = tmp.jihun[i].first + dir[j][0];
				int ny = tmp.jihun[i].second + dir[j][1];
				if (nx >= 0 && nx < row && ny >= 0 && ny < col && board[nx][ny] == '.'){
					board[nx][ny] = 'J';
					next.jihun.push_back(make_pair(nx, ny));
				}
			}
		}
		for(int i = 0; i < tmp.fire.size(); i++){
			for(int j = 0; j < 4; j++){
				int nx = tmp.fire[i].first + dir[j][0];
				int ny = tmp.fire[i].second + dir[j][1];
				if (nx >= 0 && ny < row && ny >= 0 && ny < col && (board[nx][ny] == '.' || board[nx][ny] == 'J')){
					board[nx][ny] = 'F';
					next.fire.push_back(make_pair(nx, ny));
				}
			}
		}
		print();
		que.push(next);
	}
	return (-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	info init;
	inputs(&init);
	int ans = spread(&init);
	if (ans == -1) cout << "IMPOSSIBLE\n";
	else cout << ans << "\n";
}