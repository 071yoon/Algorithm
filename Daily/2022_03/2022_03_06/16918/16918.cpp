#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int row, col, timer;
char bomb[200][200] = {0};
bool tmper[200][200] = {0};
int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void explosion(){
	memset(tmper, 0, sizeof(tmper));
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (bomb[i][j] == 'O'){
				tmper[i][j] = 1;
				for(int k = 0; k < 4; k++){
					int ni = i + directions[k][0];
					int nj = j + directions[k][1];
					if (ni >= 0 && ni < row && nj >= 0 && nj < col){
						tmper[ni][nj] = 1;
					}
				}
			}
		}
	}

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (tmper[i][j]) bomb[i][j] = '.';
			else bomb[i][j] = 'O';
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col >> timer;
	string str;
	for(int i = 0; i < row; i++){
		cin >> str;
		for(int j = 0; j < col; j++){
			bomb[i][j] = str[j];
		}
	}
	if (timer % 2 == 0){
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++)
				cout << "O";
			cout << "\n";
		}
		return (0);
	}
	for(int i = 2; i <= timer; i++){
		if (i % 2){ //explostion
			explosion();
		}
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << bomb[i][j];
		}
		cout << "\n";
	}
}