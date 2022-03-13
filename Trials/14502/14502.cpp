#include <iostream>
#include <algorithm>
using namespace std;

int row, col;
int original[8][8] = {0};
int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int copy_map[8][8];

void spread(int i, int j){
	if (copy_map[i][j] == 2){
		for(int k = 0; k < 4; k++){
			int new_i = i + direction[k][0];
			int new_j = j + direction[k][1];
			if (new_i >= 0 && new_i < row && new_j >= 0 && new_j < col){
				if (copy_map[new_i][new_j] == 0){
					copy_map[new_i][new_j] = 2;
					spread(new_i, new_j);
				}
			}
		}
	}
}

int run_test(){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++)
			copy_map[i][j] = original[i][j];
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			spread(i, j);
		}
	}
	int count = 0;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (copy_map[i][j] == 0)
				count++;
		}
	}
	return (count);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int max_num = 0;
	cin >> row >> col;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			cin >> original[i][j];
	for(int i = 0; i < row * col; i++){
		if (original[i / col][i % col] == 0){
			original[i / col][i % col] = 1;
			for(int j = i + 1; j < row * col; j++){
				if (original[j / col][j % col] == 0){
				original[j / col][j % col] = 1;
				for(int k = j + 1; k < row * col; k++){
					if (original[k / col][k % col] == 0){
						original[k / col][k % col] = 1;
						max_num = max(max_num, run_test());
						original[k / col][k % col] = 0;
					}
				}
				original[j / col][j % col] = 0;
				}
			}
			original[i / col][i % col] = 0;
		}
	}
	cout << max_num << "\n";
}