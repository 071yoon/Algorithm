#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char board[1000][1000] = {0};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int row, col;

void print(){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

void inputs(){
	cin >> row >> col;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> board[i][j];
		}
	}
}

int spread(){
	int tmp[1000][1000] = {0};
	int cnt = 0;
	while(1){
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if (board[i][j] == 'J'){
					if (i == 0 || j == 0 || i == row - 1 || j == col - 1){
						return (cnt + 1);
					}
				}
			}
		}
		int jihun_tmp = 0;
		for(int i = 0; i < row; i++){ //spread Jihun
			for(int j = 0; j < col; j++){
				if (board[i][j] == 'J'){
					tmp[i][j] = 1;
					for(int k = 0; k < 4; k++){
						int ni = i + dir[k][0];
						int nj = j + dir[k][1];
						if (ni >= 0 && ni < row && nj >= 0 && nj < col && board[ni][nj] == '.'){
							jihun_tmp++;
							tmp[ni][nj] = 1;
						}
					}
				}
			}
		}
		if (jihun_tmp == 0) return (-1);
		for(int i = 0; i < row; i++){ //spread Fire
			for(int j = 0; j < col; j++){
				if (board[i][j] == 'F'){
					tmp[i][j] = 2;
					for(int k = 0; k < 4; k++){
						int ni = i + dir[k][0];
						int nj = j + dir[k][1];
						if (ni >= 0 && ni < row && nj >= 0 && nj < col && board[ni][nj] != '#'){
							tmp[ni][nj] = 2;
						}
					}
				}
			}
		}
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if (tmp[i][j]){
					if (tmp[i][j] == 1) board[i][j] = 'J';
					else board[i][j] = 'F';
				}
			}
		}
		cnt++;
	}
	return (-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	int ans = spread();
	if (ans == -1) cout << "IMPOSSIBLE\n";
	else cout << ans << "\n";
}