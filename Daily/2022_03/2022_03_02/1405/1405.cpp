#include <iostream>
using namespace std;

int cnt; double answer = 0;
int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool visited[100][100] = {0};
double p[4] = {0};

void dfs(int x, int y, int num, double poss){
	if (poss == 0)
		return ;
	if (num == 0){
		answer += poss;
		return ;
	}
	for(int i = 0; i < 4; i++){
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];
		if (!visited[nx][ny]){
			visited[nx][ny] = 1;
			dfs(nx, ny, num - 1, poss * p[i]);
			visited[nx][ny] = 0;
		}
	}
}

int main(){
	cin >> cnt; double tmp;
	for(int i = 0; i < 4; i++){
		cin >> tmp;
		p[i] = tmp * 0.01;
	}
	visited[50][50] = 1;
	dfs(50, 50, cnt, 1);
	cout.precision(10);
	cout << fixed << answer << "\n";
}