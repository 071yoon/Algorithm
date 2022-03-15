#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, E, v1, v2;
vector <pair<int, int> > nodes[801];

void inputs(){
	cin >> N >> E;
	int num1, num2, cost;
	for(int i = 0; i < E; i++){
		cin >> num1 >> num2 >> cost;
		nodes[num1].push_back(make_pair(num2, cost));
		nodes[num2].push_back(make_pair(num1, cost));
	}
	cin >> v1 >> v2;
}

int dirk(int from, int to){
	priority_queue <pair<int, int> > que; //-cost, next node;
	que.push(make_pair(0, from));
	int tmp[801] = {0};
	for(int i = 1; i <= N; i++){
		tmp[i] = 987654321;
	}
	while(!que.empty()){
		int cur = que.top().second;
		int cost = que.top().first * -1;
		if (cur == to){
			return (cost);
		}
		que.pop();
		for(int i = 0; i < nodes[cur].size(); i++){
			int next = nodes[cur][i].first;
			int ncost = nodes[cur][i].second;
			if (tmp[next] > cost + ncost){
				tmp[next] = cost + ncost;
				que.push(make_pair((cost + ncost) * -1, next));
			}
		}
	}
	return (-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	int one_to_v1 = dirk(1, v1);
	int v1_to_v2 = dirk(v1, v2);
	int v2_to_N = dirk(v2, N);
	int one_to_v2 = dirk(1, v2);
	int v1_to_N = dirk(v1, N);
	int ret = 0;
	if (one_to_v1 == -1 || v1_to_v2 == -1 || v2_to_N == -1) ret = 0;
	else{
		ret = (one_to_v1 + v1_to_v2 + v2_to_N);
	}
	if (one_to_v2 == -1 || v1_to_v2 == -1 || v1_to_N == -1){
		if (ret == 0) cout << "-1\n";
		return (0);
	}
	else{
		ret = min(ret, one_to_v2 + v1_to_v2 + v1_to_N);
	}
	cout << ret << "\n";
}