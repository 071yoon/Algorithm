#include <iostream>
#include <cstring>
using namespace std;

int dir[8][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
int diag[4][2] = {{-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
int board[50][50] = {0};
bool cloud[50][50] = {0};
int sz, move_cnt, direction, speed, flag;

void create_four(){
	cloud[sz - 1][0] = 1;
	cloud[sz - 1][1] = 1;
	cloud[sz - 2][0] = 1;
	cloud[sz - 2][1] = 1;
}

void do_water(){
	if (flag == 0){
		create_four();
		flag = 1;
	}
	bool tmp[50][50] = {0};
	for(int i = 0; i < sz; i++){ //move
		for(int j = 0; j < sz; j++){
			if (cloud[i][j]){
				int ni = i + dir[direction][0] * speed;
				int nj = j + dir[direction][1] * speed;
				if (ni >= sz) ni %= sz;
				if (nj >= sz) nj %= sz;
				while (ni < 0) ni += sz;
				while (nj < 0) nj += sz;
				tmp[ni][nj] = 1;
				board[ni][nj] += 1;
			}
		}
	}
	memset(cloud, 0, sizeof(cloud));
	for(int i = 0; i < sz; i++){ //water duplicate
		for(int j = 0; j < sz; j++){
			if (tmp[i][j]){
				int plus = 0;
				for(int k = 0; k < 4; k++){
					int ni = i + diag[k][0];
					int nj = j + diag[k][1];
					if (ni >= 0 && nj >= 0 && ni < sz && nj < sz && board[ni][nj]){
						plus++;
					}
				}
				board[i][j] += plus;
			}
		}
	}
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			if (board[i][j] >= 2 && !tmp[i][j]){
				board[i][j] -= 2;
				cloud[i][j] = 1;
			}
		}
	}
}

void inputs(){
	cin >> sz >> move_cnt;
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			cin >> board[i][j];
		}
	}
	flag = 0;
	for(int i = 0; i < move_cnt; i++){
		cin >> direction >> speed;
		direction--;
		do_water();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	int ret = 0;
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			ret += board[i][j];
		}
	}
	cout << ret << "\n";
}