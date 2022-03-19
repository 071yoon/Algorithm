#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int node_cnt, path_cnt, start_node;
vector <pair<int, int> > paths[20001]; //node and cost
int visited[20001] = {0};

void inputs(){
	cin >> node_cnt >> path_cnt;
	cin >> start_node;
	int node1, node2, cost;
	for(int i = 0; i < path_cnt; i++){
		cin >> node1 >> node2 >> cost;
		paths[node1].push_back(make_pair(node2, cost));
	}
	for(int i = 1; i <= node_cnt; i++){
		visited[i] = INT_MAX;
	}
}

void solve(){
	priority_queue <pair<int, int> > que; //cost and node
	que.push(make_pair(0, start_node));
	visited[start_node] = 0;
	while(!que.empty()){
		int cur = que.top().second;
		int cost = que.top().first * -1;
		que.pop();
		if (visited[cur] < cost) continue;
		for(int i = 0; i < paths[cur].size(); i++){
			int next = paths[cur][i].first;
			int ncost = paths[cur][i].second + cost;
			if (visited[next] > ncost){
				visited[next] = ncost;
				que.push(make_pair(ncost * -1, next));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solve();
	for(int i = 1; i <= node_cnt; i++){
		if (visited[i] == INT_MAX) cout << "INF\n";
		else cout << visited[i] << "\n";
	}
}