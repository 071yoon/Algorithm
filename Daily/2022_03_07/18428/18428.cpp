#include <iostream>
#include <vector>
using namespace std;

int sz, flag = 0;
char school[6][6] = {0};
int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector <pair<int, int> > teacher; //x, y

bool run_test(){
	for(int i = 0; i < teacher.size(); i++){
		int x = teacher[i].first;
		int y = teacher[i].second;
		for(int j = 0; j < 4; j++){
			int nx = x + directions[j][0];
			int ny = y + directions[j][1];
			while(nx >= 0 && nx < sz && ny >= 0 && ny < sz && school[nx][ny] != 'O'){
				if (school[nx][ny] == 'T'){
					return (false);
				}
				nx = nx + directions[j][0];
				ny = ny + directions[j][1];
			}
		}
	}
	return (true);
}

void set_obstacle(int cnt, int ind){
	if (cnt == 3){
		if (run_test()){
			flag = 1;
		}
		return ;
	}
	else{
		for(int i = ind + 1; i < sz * sz; i++){
			if (school[i / sz][i % sz] == 'X'){
				school[i / sz][i % sz] = 'O';
				set_obstacle(cnt + 1, i);
				if(flag)
					return ;
				school[i / sz][i % sz] = 'X';
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> sz;
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			cin >> school[i][j];
			if (school[i][j] == 'S') teacher.push_back(make_pair(i, j));
		}
	}
	set_obstacle(0, 0);
	if (flag){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}