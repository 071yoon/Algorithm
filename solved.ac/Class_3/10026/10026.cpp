#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int sz;
int visited[101][101] = {0};
int blind_visited[101][101] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y, char color, vector <string> rgb){
	for(int i = 0; i < 4; i++){
		int now_x = x + dx[i];
		int now_y = y + dy[i];
		if (now_x >= 0 && now_x < sz && now_y >= 0 && now_y < sz && rgb[now_x][now_y] == color && !visited[now_x][now_y]){
			visited[now_x][now_y] = 1;
			DFS(now_x, now_y, color, rgb);
		}
	}
}

void blind_DFS(int x, int y, char color, vector <string> rgb){
	for(int i = 0; i < 4; i++){
		int now_x = x + dx[i];
		int now_y = y + dy[i];
		if (now_x >= 0 && now_x < sz && now_y >= 0 && now_y < sz && !blind_visited[now_x][now_y]){
			if ((color == 'R' && rgb[now_x][now_y] == 'G') || (color == 'G' && rgb[now_x][now_y] == 'R') ||
				(color == rgb[now_x][now_y])){
				blind_visited[now_x][now_y] = 1;
				blind_DFS(now_x, now_y, rgb[now_x][now_y], rgb);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> sz;
	vector <string> rgb(sz);
	string test;
	for(int i = 0; i < sz; i++)
		cin >> rgb[i];
	int cnt = 0, blind_cnt = 0;;
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			if (!visited[i][j]){
				cnt++;
				visited[i][j] = 1;
				DFS(i, j, rgb[i][j], rgb);
			}
			if (!blind_visited[i][j]){
				blind_cnt++;
				blind_visited[i][j] = 1;
				blind_DFS(i, j, rgb[i][j], rgb);
			}
		}
	}
	cout << cnt << " " << blind_cnt << "\n";
}