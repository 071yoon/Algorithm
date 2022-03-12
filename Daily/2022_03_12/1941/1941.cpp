#include <cstring>
#include <iostream>
using namespace std;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool visited[5][5] = {0};
char princess[5][5] = {0};
int ans = 0, som = 0;

void inputs(){
	string str;
	for(int i = 0; i < 5; i++){
		cin >> str;
		for(int j = 0; j < 5; j++){
			princess[i][j] = str[j];
		}
	}
	return ;
}

void solution(int x, int y, int som, int cnt){
	if (cnt == 7){
		if (som >= 4){
			ans++;
		}
		return ;
	}
	for(int i = 0; i < 4; i++){
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !visited[nx][ny]){
			visited[nx][ny] = 1;
			if (princess[nx][ny] == 'S') som++;
			solution(nx, ny, som, cnt + 1);
			if (princess[nx][ny] == 'S') som--;
			visited[nx][ny] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if (princess[i][j] == 'S') som++;
			visited[i][j] = 1;
			solution(i, j, 0, 0);
			visited[i][j] = 0;
			som = 0;
		}
	}
	cout << ans << "\n";
}