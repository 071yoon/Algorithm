#include <string>
#include <iostream>
using namespace std;

int directions[8][2] = {{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	bool visited[6][6] = {0};
	int flag = 0;
	cin >> str;
	int x = '6' - str[1];
	int y = str[0] - 'A';
	int org_x = x;
	int org_y = y;
	for(int i = 0; i < 35; i++){
		cin >> str;
		if (flag)
			continue;
		int nx = '6' - str[1];
		int ny = str[0] - 'A';
		int t_flag = 0;
		for(int j = 0; j < 8; j++){
			if (nx == x + directions[j][0] && ny == y + directions[j][1] && !visited[nx][ny]){
				visited[nx][ny] = 1;
				x = nx; y = ny;
				t_flag = 1;
				break;
			}
		}
		if (t_flag)
			continue;
		flag = 1;
	}
	if (flag){
		cout << "Invalid\n";
		return (0);
	}
	for(int i = 0; i < 8; i++){
		if (org_x == x + directions[i][0] && org_y == y + directions[i][1]){
			cout << "Valid\n";
			return (0);
		}
	}
	cout << "Invalid\n";
}