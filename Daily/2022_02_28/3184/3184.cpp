#include <iostream>
#include <cstring>
using namespace std;

char org[250][250] = {0};
bool visited[250][250] = {0};
int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int row, col;

void dfs(int x, int y, int *sheep, int *wolf){
	for(int i = 0; i < 4; i++){
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny] && org[nx][ny] != '#'){
			visited[nx][ny] = 1;
			if (org[nx][ny] == 'v') *wolf = *wolf + 1;
			else if (org[nx][ny] == 'o') *sheep = *sheep + 1;
			dfs(nx, ny, sheep, wolf);
		}
	}
}

int main(){
	string str;
	cin >> row >> col;
	for(int i = 0; i < row; i++){
		cin >> str;
		for(int j = 0; j < col; j++){
			org[i][j] = str[j];
		}
	}
	int total_sheep = 0, total_wolf = 0;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if ((org[i][j] == '.' || org[i][j] == 'o' || org[i][j] == 'v') && !visited[i][j]){
				visited[i][j] = 1;
				int sheep = 0; int wolf = 0;
				if (org[i][j] == 'o') sheep++;
				else if (org[i][j] == 'v') wolf++;
				dfs(i, j, &sheep, &wolf);
				if (wolf >= sheep){
					total_wolf += wolf;
				}
				else{
					total_sheep += sheep;
				}
			}
		}
	}
	cout << total_sheep << " " << total_wolf << "\n";
}
//7mins 45