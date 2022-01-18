#include <iostream>
#include <algorithm>
using namespace std;

int arr[500][500] = {0};
bool visit[500][500] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans = 0;
int x, y;

void DFS(int now_x, int now_y, int cnt, int ret){
	if (cnt == 3){
		ans = max(ans, ret);
		return ;
	}
	for(int i = 0; i < 4; i++){
		int new_x = now_x + dx[i];
		int new_y = now_y + dy[i];
		if (new_x < x && new_x >= 0 && new_y < y && new_y >= 0 && !visit[new_x][new_y]){
			visit[new_x][new_y] = 1;
			DFS(new_x, new_y, cnt + 1, ret + arr[new_x][new_y]);
			visit[new_x][new_y] = 0;
		}
	}
}

void check_fuck(int now_x, int now_y){
	if (now_x - 1 >= 0 && now_x + 1 < x && now_y + 1 < y)//ㅗ
		ans = max(ans, arr[now_x][now_y] + arr[now_x - 1][now_y] + arr[now_x + 1][now_y] + arr[now_x][now_y + 1]);
	if (now_x - 1 >= 0 && now_y + 1 < y && now_y - 1 >= 0)//ㅓ
		ans = max(ans, arr[now_x][now_y] + arr[now_x - 1][now_y] + arr[now_x][now_y + 1] + arr[now_x][now_y - 1]);
	if (now_x + 1 < x && now_y - 1 >= 0 && now_y + 1 < y)//ㅏ
		ans = max(ans, arr[now_x][now_y] + arr[now_x][now_y + 1] + arr[now_x][now_y - 1] + arr[now_x + 1][now_y]);
	if (now_x - 1 >= 0 && now_x + 1 < x && now_y - 1 >= 0)
		ans = max(ans, arr[now_x][now_y] + arr[now_x - 1][now_y] + arr[now_x + 1][now_y] + arr[now_x][now_y - 1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			check_fuck(i, j);
			visit[i][j] = 1;
			DFS(i, j, 0, arr[i][j]);
			visit[i][j] = 0;
		}
	}
	cout << ans << "\n";
}