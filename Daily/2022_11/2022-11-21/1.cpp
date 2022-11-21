#include <iostream>
using namespace std;

int sz;
string board[64];

bool check_flags(int x, int y, int size) {
	int flag = 0;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (board[i][j] == '1') {
				flag |= 1;
			} else if (board[i][j] == '0') {
				flag |= 2;
			} else {
				return false;
			}
		}
	}
	if (flag == 1) {
		cout << "1";
	} else if (flag == 2) {
		cout << "0";
	} else {
		return false;
	}
	return true;
}


void solve(int x, int y, int size) {
	if (check_flags(x, y, size)) return;
	cout << "(";
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			solve(x + i * size / 2, y + j * size / 2, size / 2);
		}
	}
	cout << ")";
}


int main() {
	cin >> sz;
	for(int i = 0; i < sz; i++) {
		cin >> board[i];
	}
	if(check_flags(0, 0, sz)) return 0;
	//divide and conquer paper

	solve(0, 0, sz);

	return 0;
}