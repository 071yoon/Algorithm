#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char cave[101][101] = {0};
int row, col, num;
bool visited[101][101] = {0};
int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int my_row = 0;
vector <pair<int, int> > tmp; //x, y

void isup(int x, int y){
	tmp.push_back(make_pair(x, y));
	visited[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];
		if (nx >= 1 && nx <= row && ny >= 1 && ny <= col && !visited[nx][ny] && cave[nx][ny] == 'x'){
			my_row = max(my_row, nx);
			isup(nx, ny);
		}
	}
}

void drop(int x, int y){
	for(int i = 0; i < tmp.size(); i++){
		cave[tmp[i].first][tmp[i].second] = '.';
	}
	int ind = 1;
	while(ind + my_row <= row){
		for(int i = 0; i < tmp.size(); i++){
			if (cave[tmp[i].first + ind][tmp[i].second] == 'x'){
				for(int j = 0; j < tmp.size(); j++){
					cave[tmp[j].first + ind - 1][tmp[j].second] = 'x';
				}
				return ;
			}
		}
		ind++;
	}
	for(int i = 0; i < tmp.size(); i++){
		cave[tmp[i].first + ind - 1][tmp[i].second] = 'x';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col;
	string str;
	for(int i = 1; i <= row; i++){
		cin >> str;
		for(int j = 1; j <= col; j++){
			cave[i][j] = str[j - 1];
		}
	}

	int cnt;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num; //height
		num = row - num + 1;
		if (i % 2){ //from right
			for(int i = col; i >= 1; i--){
				if (cave[num][i] == 'x'){
					cave[num][i] = '.';
					break ;
				}
			}	
		}
		else{ //from left
			for(int i = 1; i <= col; i++){
				if (cave[num][i] == 'x'){
					cave[num][i] = '.';
					break ;
				}
			}
		}

		memset(visited, 0, sizeof(visited));
		int flag = 0;
		for(int i = 1; i <= row; i++){
			for(int j = 1; j <= col; j++){
				if (cave[i][j] == 'x' && !visited[i][j]){
					tmp.clear();
					my_row = i;
					isup(i, j);
					if (my_row != row){
						flag = 1;
						drop(i, j);
						break ;
					}
				}
			}
			if (flag)
				break ;
		}
	}
	for(int i = 1; i <= row; i++){
		for(int j = 1; j <= col; j++){
			cout << cave[i][j];
		}
		cout << "\n";
	}
}