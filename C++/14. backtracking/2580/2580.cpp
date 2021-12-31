#include <iostream>
#include <vector>

int sudoku[9][9] = {0};

using namespace std;
vector <int> vec;

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
		if (sudoku[i][x] == target)
			return (0);
	}
	for (int i = 0; i < 9; i++){
		if (sudoku[y][i] == target)
			return (0);
	}
	for(int i = y / 3; i < (y / 3) + 3; i++){
		for(int j = x / 3; j < (x / 3) + 3; j++){
			if (sudoku[i][j] == target)
				return (0);
		}
	}
	return (1);
}

int solve(){
	for(int y = 0; y < 9; y++){
		for(int x = 0; x < 9; x++){
			cout << "loop 1 : x " << x << " y " << y << sudoku[y][x] << "\n";
			if (x == 8 && y == 8 && sudoku[8][8]){
				print_sudoku();
				while(1);
				return (1);
			}
			if (sudoku[y][x] == 0){
				cout << "loop 2 : x " << x << " y " << y << "\n";
				for(int i = 1; i < 10; i++){
					if (check(x, y, i)){
						cout << x << y << i << "\n";
						sudoku[y][x] = i;
						if (x == 8 && y == 8){
							print_sudoku();
							while(1);
						}
						else
							solve();
						sudoku[y][x] = 0;
					}
				}
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
			vec.push_back(num);
		}
	}

	solve();
	
}