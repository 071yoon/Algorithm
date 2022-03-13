#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int board[20][20] = {0};
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int sz, times;
int g_x, g_y;
struct shark{
	int kg = 2;
	int x;
	int y;
	int cnt = 0;
};

bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
	if (a.second == b.second){
		if (a.first.first == b.first.first){
			return a.first.second < b.first.second;
		}
		return a.first.first < b.first.first;
	}
	return a.second < b.second;
}

bool eat_fish(shark *baby){
	vector <pair<pair<int, int>, int> > food; //x, y and cnt
	g_x = baby->x;
	g_y = baby->y;
	bool visited[20][20] = {0};
	queue <pair<pair<int, int>, int> > que; //x, y and cnt
	que.push(make_pair(make_pair(baby->x, baby->y), 0));
	while(!que.empty()){
		int x = que.front().first.first;
		int y = que.front().first.second;
		int cnt = que.front().second;
		que.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < sz && ny >= 0 && ny < sz && !visited[nx][ny] && board[nx][ny] <= baby->kg){
				visited[nx][ny] = 1;
				que.push(make_pair(make_pair(nx, ny), cnt + 1));
				if (board[nx][ny] && board[nx][ny] < baby->kg)
					food.push_back(make_pair(make_pair(nx, ny), cnt + 1));
			}
		}
	}
	if (!food.size()) return (0);
	sort(food.begin(), food.end(), cmp);
	times += food[0].second;
	baby->cnt += 1;
	if (baby->cnt == baby->kg){
		baby->cnt = 0;
		baby->kg++;
	}
	baby->x = food[0].first.first;
	baby->y = food[0].first.second;
	board[baby->x][baby->y] = 0;
	return (1);
}

bool no_fish(shark *baby){
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			if (board[i][j] && board[i][j] < baby->kg) return false;
		}
	}
	return true;
}

void inputs(shark *baby){
	cin >> sz;
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			cin >> board[i][j];
			if (board[i][j] == 9){
				baby->x = i;
				baby->y = j;
				board[i][j] = 0;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	shark baby;
	inputs(&baby);
	times = 0;
	while(1){
		if (eat_fish(&baby)) continue;
		break ;
	}
	cout << times << "\n";
}