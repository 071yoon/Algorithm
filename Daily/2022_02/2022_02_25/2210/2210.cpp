#include <iostream>
#include <set>
#include <string>
using namespace std;

char nums[5][5] = {0};
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
set <string> s;
string str = "";


void solve(int x, int y, int cnt){
	if (cnt == 6){
		s.insert(str);
		return ;
	}
	for(int i = 0; i < 4; i++){
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
			str += nums[nx][ny];
			solve(nx, ny, cnt + 1);
			str.pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cin >> nums[i][j];
		}
	}
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			str += nums[i][j];
			solve(i, j, 1);
			str.pop_back();
		}
	}
	cout << s.size() << "\n";
}
//5mins 24sec
