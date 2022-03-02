#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int row, col;
int mapp[1000][1000] = {0};
bool visited[1000][1000] = {0};
bool visition[1000][1000] = {0};
int value[1000][1000][2] = {0};//value and index
int answer[1000][1000] = {0};
int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
string str;

void dfs(int x, int y, int *cnt){
	for(int i = 0; i < 4; i++){
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny] && mapp[nx][ny] == 0){
			*cnt = *cnt + 1;
			visited[nx][ny] = 1;
			dfs(nx, ny, cnt);
		}
	}
}

void fill(int x, int y, int cnt, int index){
	for(int i = 0; i < 4; i++){
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visition[nx][ny] && mapp[nx][ny] == 0){
			visition[nx][ny] = 1;
			value[nx][ny][0] = cnt;
			value[nx][ny][1] = index;
			fill(nx, ny, cnt, index);
		}
	}	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col;
	for(int i = 0; i < row; i++){
		cin >> str;
		for(int j = 0; j < col; j++){
			mapp[i][j] = str[j] - '0';
		}
	}
	int index = 0;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (mapp[i][j] == 0 && value[i][j][0] == 0){
				int cnt = 1;
				visited[i][j] = 1;
				visition[i][j] = 1;
				dfs(i, j, &cnt);
				value[i][j][0] = cnt;
				value[i][j][1] = index;
				fill(i, j, cnt, index);
				index++;
			}
		}
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if (mapp[i][j] == 1){
				int ret = 0;
				vector <int> index_list;
				for(int k = 0; k < 4; k++){
					int ni = i + directions[k][0];
					int nj = j + directions[k][1];
					if (ni >= 0 && ni < row && nj >= 0 && nj < col && mapp[ni][nj] == 0){
						int flag = 0;
						for(int r = 0; r < index_list.size(); r++){
							if (index_list[r] == value[ni][nj][1]){
								flag = 1;
								break ;
							}
						}
						if (flag)
							continue ;
						else index_list.push_back(value[ni][nj][1]);
						ret += value[ni][nj][0];
					}
				}
				answer[i][j] = ret + 1;
			}
		}
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << answer[i][j] % 10;
		}
		cout << "\n";
	}
}