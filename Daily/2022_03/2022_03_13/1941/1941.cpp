#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

char princess[5][5] = {0};
bool seven[25] = {0};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int ans = 0;

void inputs(){
	string str;
	for(int i = 0; i < 5; i++){
		cin >> str;
		for(int j = 0; j < 5; j++){
			princess[i][j] = str[j];
		}
	}
}

bool som(){
	int cnt = 0;
	for(int i = 0; i < 25; i++){
		if (seven[i]){
			if (princess[i / 5][i % 5] == 'S') cnt++;
		}
	}
	if (cnt >= 4){
		return true;
	}
	return false;
}

bool adj(){
	queue <pair<int, int> > que;
	vector <pair<int, int> > vec;
	for(int i = 0; i < 25; i++){
		if (seven[i]) vec.push_back(make_pair(i / 5, i % 5));
	}
	que.push(make_pair(vec[vec.size() - 1].first, vec[vec.size() - 1].second));
	vec.pop_back();
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
				for(int k = 0; k < vec.size(); k++){
					if (nx == vec[k].first && ny == vec[k].second){
						vec.erase(vec.begin() + k);
						que.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	if (vec.empty()) return true;
	return false;
}

void dfs(int index, int cnt){
	if (cnt == 7){
		if (som() && adj()) ans++;
		return ;
	}
	for(int i = index; i < 25; i++){
		seven[i] = 1;
		dfs(i + 1, cnt + 1);
		seven[i] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	dfs(0, 0);
	cout << ans << "\n";
}