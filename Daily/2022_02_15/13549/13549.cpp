#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

bool visited[100001] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int now, des;
	cin >> now >> des;
	priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >  > que;//cnt, location
	que.push(make_pair(0, now));
	visited[now] = 1;
	while(!que.empty()){
		int cnt = que.top().first;
		int loc = que.top().second;
		que.pop();
		if (loc == des){
			cout << cnt << "\n";
			return (0);
		}
		if (2 * loc <= 100000 && !visited[2*loc]){
			visited[2*loc] = 1;
			que.push(make_pair(cnt, 2 * loc));
		}
		if (loc + 1 <= 100000 && !visited[loc + 1]){
			visited[loc + 1] = 1;
			que.push(make_pair(cnt + 1, loc + 1));
		}
		if (loc - 1 >= 0 && !visited[loc - 1]){
			visited[loc - 1] = 1;
			que.push(make_pair(cnt + 1, loc - 1));
		}
	}
}