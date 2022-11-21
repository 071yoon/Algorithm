#include <iostream>
#include <map>
#include <queue>
using namespace std;


int main() {
	int n, jump;
	bool visited[1000001] = { false, };
	cin >> n >> jump;
	map<int, int> m;
	for(int i = 0; i < jump; i++) {
		int a, b;
		cin >> a >> b;
		m[a] = b;
		m[b] = a;
	}

	// dfs with dice game
	queue <pair<int, int> > q;
	q.push(make_pair(0, 0));
	visited[0] = true;
	while(!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if(cur == n) {
			cout << cnt << "\n";
			return 0;
		}
		for(int i = 1; i <= 6; i++) {
			int next = cur + i;
			if(next > n) continue;
			if(visited[next]) continue;
			visited[next] = true;
			if (m[next] != NULL && !visited[m[next]]) {
				visited[next] = true;
				q.push(make_pair(m[next], cnt + 1));
			} else {
				q.push(make_pair(next, cnt + 1));
			}
		}
	}
	cout << -1 << "\n";

	return 0;
}