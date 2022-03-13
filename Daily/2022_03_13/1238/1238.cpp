#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int total_cost[1001] = {0};
int people_cnt, road_cnt, target;
vector <pair<int, int> > road[1001]; //next node, cost

void inputs(){
	cin >> people_cnt >> road_cnt >> target;
	int starter, ender, cost;
	for(int i = 0; i < road_cnt; i++){
		cin >> starter >> ender >> cost;
		road[starter].push_back(make_pair(ender, cost));
	}
}

void first_track(int me){
	int tmp[1001] = {0};
	for(int i = 1; i <= people_cnt; i++) tmp[i] = 987654321;
	priority_queue <pair<int, int> > que; //cost and next node
	que.push(make_pair(0, me));
	tmp[me] = 0;
	while(!que.empty()){
		int cost = que.top().first * -1;
		int node = que.top().second;
		que.pop();
		if (cost > tmp[node]) continue ;
		if (node == target){
			total_cost[me] += cost;
			return; 
		}
		for(int i = 0; i < road[node].size(); i++){
			int next_node = road[node][i].first;
			if (tmp[next_node] > cost + road[node][i].second){
				tmp[next_node] = cost + road[node][i].second;
				que.push(make_pair(tmp[next_node] * -1, next_node));
			}
		}
	}
}

void spread(){
	int tmp[1001] = {0};
	for(int i = 1; i <= people_cnt; i++) tmp[i] = 987654321;
	priority_queue <pair<int, int> > que;
	que.push(make_pair(0, target));
	tmp[target] = 0;
	while(!que.empty()){
		int cost = que.top().first * -1;
		int node = que.top().second;
		que.pop();
		if (cost > tmp[node]) continue ;
		for(int i = 0; i < road[node].size(); i++){
			int next_node = road[node][i].first;
			int next_cost = road[node][i].second;
			if (tmp[next_node] > cost + next_cost){
				tmp[next_node] = cost + next_cost;
				que.push(make_pair(tmp[next_node] * -1, next_node));
			}
		}
	}
	for(int i = 1; i <= people_cnt; i++){
		total_cost[i] += tmp[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	for(int i = 1; i <= people_cnt; i++){
		first_track(i);
	}
	spread();
	cout << *max_element(total_cost, total_cost + people_cnt + 1) << "\n";
}