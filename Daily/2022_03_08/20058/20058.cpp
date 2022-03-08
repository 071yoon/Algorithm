#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int sz, biggest = 0, tmp_big;
int ice[64][64] = {0};
int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool visited[64][64] = {0};

void rotate(int x, int y, int num){
	for(int i = 0; i < num; i++){
		for(int j = i; j < num; j++){
			swap(ice[x + i][y + j], ice[x + j][y + i]);
		}
	}
	for(int i = x; i < x + num; i++){
		reverse(ice[i] + y, ice[i] + y + num);
	}
}

void melt(){
	bool tmp[64][64] = {0};
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			int cur = 0;
			for(int k = 0; k < 4; k++){
				int ni = i + directions[k][0];
				int nj = j + directions[k][1];
				if (ni >= 0 && ni < sz && nj >= 0 && nj < sz && ice[ni][nj] > 0){
					cur++;
				}
			}
			if (cur <= 2){
				tmp[i][j] = 1;
			}
		}
	}
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			if (tmp[i][j] && ice[i][j]) ice[i][j]--;
		}
	}
}

void find_biggest(int x, int y){
	tmp_big++;
	visited[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];
		if (nx >= 0 && nx < sz && ny >= 0 && ny < sz && !visited[nx][ny] && ice[nx][ny] > 0){
			find_biggest(nx, ny);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num;
	cin >> sz >> cnt;
	sz = pow(2, sz);
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			cin >> ice[i][j];
		}
	}
	for(int i = 0; i < cnt; i++){
		cin >> num;
		num = pow(2, num);
		for(int x = 0; x < sz; x += num){
			for(int y = 0; y < sz; y += num){
				rotate(x, y, num);
			}
		}
		melt();
	}
	int ret = 0;
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			ret += ice[i][j];
			if (!visited[i][j] && ice[i][j] > 0){
				tmp_big = 0;
				find_biggest(i, j);
				biggest = max(biggest, tmp_big);
			}
		}
	}
	cout << ret << "\n" << biggest << "\n";
}