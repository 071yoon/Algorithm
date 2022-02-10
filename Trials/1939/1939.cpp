#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

int isl_cnt, bdg_cnt;
int strt_isl, end_isl;
vector <pair<int, int> > islands[10001];

bool bfs(int val){
	bool visited[10001] = {0};
	queue <int> que;
	que.push(strt_isl);
	visited[strt_isl] = 1;
	while(!que.empty()){
		int now = que.front();
		que.pop();
		if (now == end_isl){
			return 1;
		}
		for(int i = 0; i < islands[now].size(); i++){
			int next = islands[now][i].first;
			int cost = islands[now][i].second;
			if (!visited[next] && val <= cost){
				visited[next] = 1;
				que.push(next);
			}
		}
	}
	return (0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> isl_cnt >> bdg_cnt;
	int tmp1, tmp2, tmp3, min_val = INT_MAX, max_val = 0;
	for(int i = 0; i < bdg_cnt; i++){
		cin >> tmp1 >> tmp2 >> tmp3;
		islands[tmp1].push_back(make_pair(tmp2, tmp3));
		islands[tmp2].push_back(make_pair(tmp1, tmp3));
		min_val = min(min_val, tmp3);
		max_val = max(max_val, tmp3);
	}
	cin >> strt_isl >> end_isl;
	int starter = min_val, ender = max_val;
	int ret = 0;
	while(starter <= ender){
		int mid = (starter + ender) / 2;
		if (bfs(mid)){
			ret = mid;
			starter = mid + 1;
		}
		else{
			ender = mid - 1;
		}
	}
	cout << ret << "\n";
}