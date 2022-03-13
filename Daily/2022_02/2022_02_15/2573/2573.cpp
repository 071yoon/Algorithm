#include <iostream>
using namespace std;

int ice[300][300] = {0};
int row, col;
int directions[4][2] =  {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void copy_map(int before[300][300], int copy[300][300]){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			copy[i][j] = before[i][j];
		}
	}
}

void dfs(bool visited[300][300], int x, int y){
	visited[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];
		if (nx >= 0 && ny >= 0 && nx < row && ny < col && !visited[nx][ny] && ice[nx][ny]){
			dfs(visited, nx, ny);
		}
	}
}

int check_ices(){
	int cnt = 0;
	bool visited[300][300] = {0};
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (ice[i][j] && !visited[i][j]){
				cnt++;
				dfs(visited, i, j);
			}
		}
	}
	return (cnt);
}

int check_surr(int x, int y){
	int cnt = 0;
	for(int i = 0; i < 4; i++){
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col && ice[nx][ny] == 0){
			cnt++;
		}
	}
	return (cnt);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> ice[i][j];
		}
	}
	int year = 0;
	while (1){
		if (check_ices() >= 2){
			cout << year << "\n";
			return (0);
		}
		if (check_ices() == 0){
			cout << "0\n";
			return (0);
		}
		int copy[300][300] = {0};
		copy_map(ice, copy);
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if (ice[i][j]){
					copy[i][j] -= check_surr(i, j);
					if (copy[i][j] < 0)
						copy[i][j] = 0;
				}
			}
		}
		copy_map(copy, ice);
		/*
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				cout << ice[i][j] << " ";
			}
			cout << "\n";
		}
		*/
		year++;
	}
}