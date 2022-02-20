#include <iostream>
#include <queue>
using namespace std;

struct info{
	int x;
	int y;
};
int row, col;
int timer[50][50] = {0};
char org[50][50] = {0};
int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col;
	int house_x, house_y;
	queue <info> go;//x, y
	queue <info> water;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> org[i][j];
			if (org[i][j] == '*'){
				info s; s.x = i; s.y = j;
				water.push(s);
			}
			else if (org[i][j] == 'D'){
				house_x = i; house_y = j;
			}
			else if (org[i][j] == 'S'){
				info s; s.x = i; s.y = j;
				timer[i][j] = 1;
				go.push(s);
			}
		}
	}
	while(!go.empty()){

		int go_sz = go.size();
		for(int i = 0; i < go_sz; i++){
			int x = go.front().x;
			int y = go.front().y;
			go.pop();
			if (org[x][y] != 'S')
				continue ;
			for(int j = 0; j < 4; j++){
				int nx = x + directions[j][0];
				int ny = y + directions[j][1];
				if (nx >= 0 && nx < row && ny >= 0 && ny < col){
					if (org[nx][ny] == 'D'){
						cout << timer[x][y] << "\n";
						return (0);
					}
					else if (org[nx][ny] == '.'){
						org[nx][ny] = 'S';
						timer[nx][ny] = timer[x][y] + 1;
						info s; s.x = nx; s.y = ny;
						go.push(s);
					}
				}
			}
		}
		int water_sz = water.size();
		for(int i = 0; i < water_sz; i++){
			int x = water.front().x;
			int y = water.front().y;
			water.pop();
			for(int j = 0; j < 4; j++){
				int nx = x + directions[j][0];
				int ny = y + directions[j][1];
				if (nx >= 0 && nx < row && ny >= 0 && ny < col && (org[nx][ny] == '.' || org[nx][ny] == 'S')){
					org[nx][ny] = '*';
					info s; s.x = nx; s.y = ny;
					water.push(s);
				}
			}
		}
		/*
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				cout << org[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/
	}
	cout << "KAKTUS\n";
}
/*
물을 먼저 번지게 만들고 여기 고슴도치 있으면 컷
오리지널 맵에서 홍수 일으키고 홍수 일어날 자리에 고슴도치 있어도 번짐 -> org D, X, * 아니면 걍 다 번짐
고슴도치는 오리지널에 있어야 번질 수 있음
X 나 D 는 번지지 못하고, 고슴도치 D 에 도착하면 끝

D . *    D * *    D * *
. . . -> . S * -> S * *
. S .    S S S    S S *

*/