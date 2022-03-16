#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int node_cnt, road_cnt, worm_cnt;
vector <pair<int, int> > roads[501];
vector <pair<int, int> > worms[501];

int solution(int node1, int node2){
	
}

void inputs(){
	int T;
	cin >> T;
	while(T--){
		memset(roads, 0, sizeof(roads));
		memset(worms, 0, sizeof(worms));
		cin >> node_cnt >> road_cnt >> worm_cnt;
		int node1, node2, cost;
		for(int i = 0; i < road_cnt; i++){
			cin >> node1 >> node2 >> cost;
			roads[node1].push_back(make_pair(node2, cost));
			roads[node2].push_back(make_pair(node1, cost));
		}
		for(int i = 0; i < worm_cnt; i++){
			cin >> node1 >> node2 >> cost;
			int min_dist = solution(node1, node2);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
}