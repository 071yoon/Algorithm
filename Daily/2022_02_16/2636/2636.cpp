#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int row, col;
int cheese[100][100] = {0};
int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector <int> left_cheese;

void copy_cheese(int copied[100][100], int copy[100][100]){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			copied[i][j] = copy[i][j];
		}
	}
}

bool check_cheese(int x, int y){
	for(int i = 0; i < 4; i++){
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];
		if (cheese[nx][ny] != 0){
			continue ;
		}
		if (nx == 0 || (nx == row - 1) || ny == 0 || (ny == col - 1)){
			return (true);
		}
		bool visited[100][100] = {0};
		queue <pair<int, int> > que;
		que.push(make_pair(nx, ny));
		visited[nx][ny] = 1;
		while (!que.empty()){
			int new_x = que.front().first;
			int new_y = que.front().second;
			if (new_x == 0 || new_x == row - 1 || new_y == 0 || new_y == col - 1)
				return (true);
			que.pop();
			for(int i = 0; i < 4; i++){
				int nnx = new_x + directions[i][0];
				int nny = new_y + directions[i][1];
				if (nnx >= 0 && nnx < row && nny >= 0 && nny < col && !visited[nnx][nny] && cheese[nnx][nny] == 0){
					visited[nnx][nny] = 1;
					que.push(make_pair(nnx, nny));
				}
			}
		}
	}
	return (false);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> cheese[i][j];
		}
	}
	int ret = 0;
	int cheese_cnt = 0;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (cheese[i][j] == 1)
				cheese_cnt++;
		}
	}
	left_cheese.push_back(cheese_cnt);
	while (1){
		int flag = 1;

		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if (cheese[i][j] != 0){
					flag = 0;
					break ;
				}
			}
		}
		if (flag){
			cout << ret << "\n";
			cout << left_cheese[left_cheese.size() - 1] << "\n";
			return 0;
		}
		ret++;
		cheese_cnt = 0;
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if (cheese[i][j] == 1)
					cheese_cnt++;
			}
		}
		left_cheese.push_back(cheese_cnt);
		int tmp_cheese[100][100] = {0};
		copy_cheese(tmp_cheese, cheese);
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if (cheese[i][j] == 1 && check_cheese(i, j)){
					tmp_cheese[i][j] = 0;
				}
			}
		}
		copy_cheese(cheese, tmp_cheese);
	}
}