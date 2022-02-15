#include <queue>
#include <iostream>
#include <vector>
using namespace std;

int map_sz, active_cnt;
int original[50][50] = {0};
int ret = -1;
int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector <pair<int, int> > active_virus;
vector <pair<int, int> > virus;

void copy_map(int copied[50][50], int copy[50][50]){
	for(int i = 0; i < map_sz; i++){
		for(int j = 0; j < map_sz; j++)
			copied[i][j] = copy[i][j];
	}
}

void solve(){
	int copy[50][50];
	int timer[50][50];
	for(int i = 0; i < map_sz; i++){
		for(int j = 0; j < map_sz; j++)
			timer[i][j] = -1;
	}
	copy_map(copy, original);
	queue <pair<int, int> > que;
	for(int i = 0; i < active_virus.size(); i++){
		que.push(make_pair(active_virus[i].first, active_virus[i].second));
		timer[active_virus[i].first][active_virus[i].second] = 0;
	}
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (nx >= 0 && nx < map_sz && ny >= 0 && ny < map_sz && (copy[nx][ny] == 0 || copy[nx][ny] == 2) && timer[nx][ny] == -1){
				timer[nx][ny] = timer[x][y] + 1;
				copy[nx][ny] = 3;
				que.push(make_pair(nx, ny));
			}
		}
	}
	/*
	for(int i = 0; i < map_sz; i++){
		for(int j = 0; j < map_sz; j++){
			cout << copy[i][j] << " ";
		}
		cout << "\n";
	}*/
	int tmp = 0;
	for(int i = 0; i < map_sz; i++){
		for(int j = 0; j < map_sz; j++){
			if (copy[i][j] == 3 && original[i][j] == 0){
				tmp = max(timer[i][j], tmp);
			}
			if (copy[i][j] == 0){
				return ;
			}
		}
	}
	if (ret == -1)
		ret = tmp;
	else
		ret = min(ret, tmp);
}

void solved(int cnt, int index){
	if (cnt == active_cnt){
		solve();
		return ;
	}
	for(int i = index; i < virus.size(); i++){
		int x = virus[i].first;
		int y = virus[i].second;
		active_virus.push_back(make_pair(x, y));
		solved(cnt + 1, i + 1);
		active_virus.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> map_sz >> active_cnt;
	for(int i = 0; i < map_sz; i++){
		for(int j = 0; j < map_sz; j++){
			cin >> original[i][j];
			if (original[i][j] == 2){
				virus.push_back(make_pair(i, j));
			}
		}
	}

	solved(0, 0);
	cout << ret << "\n";
}

/*

우선 바이러스 위치를 pair <x, y> 로 저장해서 무작위로 M 개를 고르는 작업이 필요
활성화할 바이러스를 3으로 바꾸고 나머지는 2로 유지
끝났다면 테스트를 돌린다 -> BFS 로 전부 3으로 바꾸면서, 큐 다 쓰면 끝 -> 테스트해보고 0이 있으면 max = -1


*/