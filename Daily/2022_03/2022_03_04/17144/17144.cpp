#include <iostream>
using namespace std;

int mapp[51][51] = {0};
int row, col, cnt;
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void air(){
	/*
	 int index = 0;
	while (mapp[index][0] != -1) {
		index += 1;
	}
	// 위에서 아래
	for (int i = 1; i < index; i++) {
		mapp[index-i][0] = mapp[index-(i+1)][0];
	}
	// 위쪽
	for (int i = 0; i < col-1; i++) {
		mapp[0][i] = mapp[0][i+1];
	}
	// 아래에서 위
	for (int i = 0; i < index; i++) {
		mapp[i][col-1] = mapp[i+1][col-1];
	}
	// 가운데
	for (int i = col-1; i > 1; i--) {
		mapp[index][i] = mapp[index][i-1];
	}
	mapp[index][1] = 0;

	// ==================================
	// 아래에서 위
	for (int i = index+2; i < row-1; i++) {
		mapp[i][0] = mapp[i+1][0];
	}
	// 아래쪽
	for (int i = 0; i < col; i++) {
		mapp[row-1][i] = mapp[row-1][i+1];
	}
	// 위에서 아래
	for (int i = row-1; i > index+1; i--) {
		mapp[i][col-1] = mapp[i-1][col-1];
	}
	// 가운데
	for (int i = col-1; i > 1; i--) {
		mapp[index+1][i] = mapp[index+1][i-1];
	}
	mapp[index+1][1] = 0;

	
	for(int i = 0; i < col; i++){
		if (mapp[i][0] == -1){ //up
			for (int i = 1; i < index; i++) {
				mapp[index-i][0] = mapp[index-(i+1)][0];
			}
			// 위쪽
			for (int i = 0; i < col-1; i++) {
				mapp[0][i] = mapp[0][i+1];
			}
			// 아래에서 위
			for (int i = 0; i < index; i++) {
				mapp[i][col-1] = mapp[i+1][col-1];
			}
			// 가운데
			for (int i = col-1; i > 1; i--) {
				mapp[index][i] = mapp[index][i-1];
			}
			mapp[i][1] = 0;
			i = i + 1;
			for(int j = i + 2; j < row; j++){
				mapp[j - 1][0] = mapp[j][0];
			}
			for(int j = 1; j < col; j++){
				mapp[row - 1][j - 1] = mapp[row - 1][j];
			}
			for(int j = row - 2; j >= i; j--){
				mapp[j + 1][col - 1] = mapp[j][col - 1];
			}
			for(int j = col - 2; j >= 1; j--){
				mapp[i][j + 1] = mapp[i][j];
			}
			mapp[i][1] = 0;
			break ;
		}
	}
	
}

void spread(){
	int tmp[51][51] = {0};
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (mapp[i][j] > 0){
				int tmper = 0;
				int val = mapp[i][j] / 5;
				for(int k = 0; k < 4; k++){
					int ni = i + directions[k][0];
					int nj = j + directions[k][1];
					if (ni >= 0 && ni < row && nj >= 0 && nj < col && mapp[ni][nj] != -1){
						tmp[ni][nj] = tmp[ni][nj] + val;
						tmper++;
					}
				}
				tmp[i][j] = tmp[i][j] - val * tmper;
			}
		}
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			mapp[i][j] += tmp[i][j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col >> cnt;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> mapp[i][j];
		}
	}
	while(cnt--){
		spread();
		air();
	}
	int ret = 0;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (mapp[i][j] >= 1){
				ret += mapp[i][j];
			}
		}
	}
	cout << ret << "\n";
}