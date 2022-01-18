#include <iostream>

int sudoku[9][9] = {0};

using namespace std;

void print_sudoku(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}
}

int check(int x, int y, int target){
	for(int i = 0; i < 9; i++){
		if (sudoku[i][x] == target){
			return (0);
		}
	}
	for (int i = 0; i < 9; i++){
		if (sudoku[y][i] == target){
			return (0);
		}
	}
	for(int i = 3 * (y / 3); i < 3 * (y / 3) + 3; i++){
		for(int j = 3 * (x / 3); j < 3 * (x / 3) + 3; j++){
			if (sudoku[i][j] == target){
				return (0);
			}
		}
	}
	return (1);
}

int solve(){
	for(int y = 0; y < 9; y++){
		for(int x = 0; x < 9; x++){
			if (x == 8 && y == 8 && sudoku[8][8]){
				print_sudoku();
				return (1);
			}
			if (sudoku[y][x] == 0){
				for(int i = 1; i < 10; i++){
					if (check(x, y, i)){
						sudoku[y][x] = i;
						if (x == 8 && y == 8){
							print_sudoku();
							return (1);
						}
						else{
							if (solve())
								return (1);
						}
						sudoku[y][x] = 0;
					}
				}
				return (0);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin >> num;
			sudoku[i][j] = num;
		}
	}

	solve();
	
}