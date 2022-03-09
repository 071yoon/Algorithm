#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector <pair<int, int> > farm[50001]; //farm1 -> farm2 and cost
int dist[50001];
int farm_cnt, cnt;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> farm_cnt >> cnt;
	int num1, num2, num3;
	for(int i = 0; i < cnt; i++){
		cin >> num1 >> num2 >> num3;
		farm[num1].push_back(make_pair(num2, num3));
		farm[num2].push_back(make_pair(num1, num3));
	}
	for(int i = 1; i <= farm_cnt; i++) dist[i] = 987654321;
	priority_queue <pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, 1));
	while(!pq.empty()){
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[now] < cost) continue;
		for(int k = 0; k < farm[now].size(); k++){
			int next = farm[now][k].first;
			int next_cost = farm[now][k].second;
			if (dist[next] > next_cost + cost){
				dist[next] = next_cost + cost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
	cout << dist[farm_cnt] << "\n";
}