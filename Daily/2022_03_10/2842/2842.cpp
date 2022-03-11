#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int sz, sx, sy, houses = 0, total_house = 0;
char org[50][50] = {0};
int	tired[50][50] = {0};
bool visited[50][50] = {0};
int dir[8][2] = {{-1, 0}, {-1, -1}, {-1, 1}, {1, 0}, {1, -1}, {1, 1}, {0, 1}, {0, -1}};
vector <int> fatigue;

void bfs(int sx, int sy, int low, int high){
	queue <pair<int, int> > que;
	que.push(make_pair(sx, sy));
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for(int i = 0; i <  8; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < sz && ny >= 0 && ny < sz){
				if (!visited[nx][ny] && tired[nx][ny] >= fatigue[low] && tired[nx][ny] <= fatigue[high]){
					visited[nx][ny] = 1;
					que.push(make_pair(nx, ny));
					if (org[nx][ny] == 'K') houses++;
				}
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
			cin >> org[i][j];
			if (org[i][j] == 'P'){
				sx = i; sy = j;
			}
			else if (org[i][j] == 'K'){
				total_house++;
			}
		}
	}
	int tmp;
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			cin >> tmp;
			tired[i][j] = tmp;
			fatigue.push_back(tmp);
		}
	}
	sort(fatigue.begin(), fatigue.end());
	fatigue.erase(unique(fatigue.begin(), fatigue.end()), fatigue.end());
	int low = 0, high = 0;
	int ret = 987654321;
	while(low < fatigue.size()){
		memset(visited, 0, sizeof(visited));
		int cur = tired[sx][sy];
		houses = 0;
		if (cur >= fatigue[low] && cur <= fatigue[high]){
			visited[sx][sy] = 1;
			bfs(sx, sy, low, high);
		}
		if (houses == total_house){
			ret = min(ret, fatigue[high] - fatigue[low]);
			low++;
		}
		else if (high + 1 < fatigue.size()) high++;
		else break;
	}
	cout << ret << "\n";
}