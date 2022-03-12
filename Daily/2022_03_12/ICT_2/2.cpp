#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dir[2][4][2] = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

vector<vector<int> > solution(int n, bool clockwise) {
    vector<vector<int> > answer;
    int board[1001][1001] = {0};
    pair<int, int> next[4];
	board[0][0] = 1;
	board[0][n - 1] = 1;
	board[n - 1][n - 1] = 1;
	board[n - 1][0] = 1;

	if (clockwise){
		next[0] = make_pair(0, 0);
		next[1] = make_pair(0, n - 1);
		next[2] = make_pair(n - 1, n - 1);
		next[3] = make_pair(n - 1, 0);
	}
	else{
		next[0] = make_pair(0, 0);
		next[1] = make_pair(n - 1, 0);
		next[2] = make_pair(n - 1, n - 1);
		next[3] = make_pair(0, n - 1);
	}
    int flag = 1;
    if (clockwise) flag = 0;
    else flag = 1;
	int idx = 0;
	int end_flag = 0;
    while (1){
        for(int i = 0; i < 4; i++){
			int x = next[i].first;
			int y = next[i].second;
			while(1){
				int nx = x + dir[flag][idx][0];
				int ny = y + dir[flag][idx][1];
				if (!board[nx][ny]){
					board[nx][ny] = board[x][y] + 1;
					x = nx;
					y = ny;
				}
				else{
					break ;
				}
			}
			idx = (idx + 1) % 4;
			int nx = x + dir[flag][idx][0];
			int ny = y + dir[flag][idx][1];
			if (!board[nx][ny]){
 				board[nx][ny] = board[x][y] + 1;
				next[i] = make_pair(nx, ny);
			}
			else{
				end_flag = 1;
			}
        }
		if (end_flag) break;
		idx = (idx + 1) % 4;
    }
	for(int i = 0; i < n; i++){
		vector <int> tmp;
		for(int j = 0; j < n; j++){
			tmp.push_back(board[i][j]);
		}
		answer.push_back(tmp);
	}
    return answer;
}
int main(){
	int n = 9;
	bool clockwise = false;
	solution(n, clockwise);
}