#include <iostream>
using namespace std;

int directions[3][2] = {{0, -1}, {-1, 0}, {0, 1}};

int row, col, range;
int origin[16][15] = {0};
int ret = 0;

void copy(int copied[16][15], int copy[16][15]){
	for(int i = 0; i < row + 1; i++){
		for(int j = 0; j < col; j++){
			copied[i][j] = copy[i][j];
		}
	}
}

void solve(){
	for(int i = 0; i < row + 1; i++){
		for(int j = 0; j < col; j++){
			cout << origin[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	int tmp[16][15];
	copy(tmp, origin);
	for(int i = 0; i < col; i++){
		if (origin[row][i] == 3){
			
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col >> range;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> origin[i][j];
		}
	}
	for(int i = 0; i < col - 2; i++){
		origin[row][i] = 3;
		for(int j = i + 1; j < col - 1; j++){
			origin[row][j] = 3;
			for(int k = j + 1; k < col; k++){
				origin[row][k] = 3;
				solve();
				origin[row][k] = 0;
			}
			origin[row][j] = 0;
		}
		origin[row][i] = 0;
	}
}

/*

1 1 1 1 1    1 1 1 1 1
1 1 1 1 1    1 1 1 1 1
1 1 1 1 1 -> 1 1 1 1 1
1 1 1 1 1    1 1 1 1 1 
1 1 1 1 1    1 1 1 1 1
3 0 3 0 3    3 0 3 0 3

1 0 1 0 1
0 1 0 1 0
1 1 0 0 0
0 0 0 1 1
1 1 0 1 1
0 0 1 0 0
3 0 0 3 3

row, col 그리고 (row+1)에 col 사이즈 짜리의 궁수 배치 -> for 세개로
쏘기 전에 tmp 저장 -> 궁수가 쏘고, tmp 1 이면 들어가고 -> original 1에서 0 바꿀 때 마다 ret++
애들 다 쏘면 궁수 위치 한칸 위로 올리고 반복 -> 궁수가 row 0 에 도달하면 끗!

*/