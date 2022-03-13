#include <iostream>
#include <algorithm>
using namespace std;

int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int house[50][50];
int row, col, x, y, d, cnt = 0;

int test_cycle(){
	for(int i = 0; i < 4; i++){
		d--;
		if (d == -1) d = 3;
		int new_x = x + direction[d][0];
		int new_y = y + direction[d][1];
		if (new_x >= 1 && new_x < row && new_y >= 1 && new_y < col && house[new_x][new_y] == 0){
			x = new_x;
			y = new_y;
			return (1);
		}
	}
	return (0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col;
	cin >> x >> y >> d;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++)
			cin >> house[i][j];
	}
	while(1){
		if (house[x][y] == 0){
			house[x][y] = 2;
			cnt++;
		}
		if (test_cycle()){//moved
			continue ;
		}
		else{//all walls
			int back_x = x - direction[d][0];
			int back_y = y - direction[d][1];
			//go behind
			if (back_x < 1 || back_x >= row - 1 || back_y < 1 || back_y >= col - 1 || house[back_x][back_y] == 1)
				break ;
			x = back_x;
			y = back_y;
			continue;
			//if can't move -> return
		}

	}
	cout << cnt << "\n";
}