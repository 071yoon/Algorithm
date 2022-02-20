#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int row, col;
int table[50][50] = {0};
int ret = 1;

void test_sq(int x, int y){
	int lim = min(row - x, col - y);
	for(int i = 1; i < lim; i++){
		int x2 = x + i;
		int y2 = y + i;
		if (table[x][y] == table[x2][y] && table[x][y] == table[x][y2] && table[x][y] == table[x2][y2]){
			ret = max(ret, (x2 - x + 1) * (x2 - x + 1));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string str;

	cin >> row >> col;
	for(int i = 0; i < row; i++){
		cin >> str;
		for(int j = 0; j < str.length(); j++){
			table[i][j] = str[j] - '0';
		}
	}
	for(int i = 0; i < row - 1; i++){
		for(int j = 0; j < col - 1; j++){
			test_sq(i, j);
		}
	}
	cout << ret << "\n";
}
//8mins 20sec