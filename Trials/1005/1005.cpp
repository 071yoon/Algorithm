#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;



int solve(){
	int N, K, num1, num2, ret;
	cin >> N >> K;
	int price[1001];
	int summer[1002] = {0};
	bool visited[1001] = {0};
	vector <int> graph[1001];
	queue <pair<int, int> > que;
	for(int i = 1; i <= N; i++){
		cin >> price[i];
	}
	for(int i = 0; i < K; i++){
		cin >> num1 >> num2;
		graph[num2].push_back(num1);
	}
	cin >> ret;
	int total = 0;
	int cntr = 0;
	que.push(make_pair(ret, cntr));
	total += price[ret];
	visited[ret] = 1;
	while(!que.empty()){
		int num = que.front().first;
		cntr = que.front().second;
		que.pop();
		for(int i = 0; i < graph[num].size(); i++){
			if (!visited[graph[num][i]]){
				visited[graph[num][i]] = 1;
				summer[cntr] = max(summer[cntr], price[graph[num][i]]);
				que.push(make_pair(graph[num][i], cntr + 1));
			}
		}
	}
	for(int i = 0; i < cntr; i++){
		total += summer[i];
	}
	cout << total << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--){
		solve();
	}	
}