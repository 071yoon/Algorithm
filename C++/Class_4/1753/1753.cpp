#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

vector <pair <int, int> > graph[20001];
priority_queue <pair <int, int> > pq;
int graph_cost[20001];

int V, E, start;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int node1, node2, tmp_cost;
	cin >> V >> E;
	cin >> start;
	for(int i = 0; i < E; i++){
		cin >> node1 >> node2 >> tmp_cost;
		graph[node1].push_back(make_pair(node2, tmp_cost));
	}
	for(int i = 1; i <= V; i++)
		graph_cost[i] = INT_MAX;
	pq.push(make_pair(0, start));
	graph_cost[start] = 0;
	while(!pq.empty()){
		int cost = -pq.top().first;
		//우선순위큐를 위해 -를 붙여둔 것을 다시 복귀
		int cur_node = pq.top().second;
		pq.pop();
		for(int i = 0; i < graph[cur_node].size(); i++){
			int next = graph[cur_node][i].first;
			int next_cost = graph[cur_node][i].second;
			if (graph_cost[next] > cost + next_cost){
				graph_cost[next] = cost + next_cost;
				pq.push(make_pair(-graph_cost[next], next));
				//우선순위 큐를 활용하여, 제일 높은 cost일수록 우선순위를 뒤로 미룬다
				//어차피 뒤에 있을수록 나중에 search를 하여 연산량이 적어진다
			}
		}
	}
	for(int i = 1; i <= V; i++){
		if (graph_cost[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << graph_cost[i] << "\n";
	}
}