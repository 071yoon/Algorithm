#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, m, u, v;
bool visit[501];
vector<int> graph[501];

bool DFS(int x, int post_x){
	visit[x] = true;
	for (int i = 0; i < graph[x].size(); i++){
		if (graph[x][i] == post_x) //전에 출발했던 노드인 경우 pass
			continue;
		if (visit[graph[x][i]]) //중복 있다면 cycle 존재
			return false;
		if (DFS(graph[x][i], x) == false) //다음 node검색 하는데 중복있다면 false
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt = 1;
	int ans;
	while (1){
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		ans = 0;
		memset(visit, 0, sizeof(visit));
		memset(graph, 0, sizeof(graph));
		for (int i = 0; i < m; i++){
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 1; i <= n; i++){
			if (!visit[i])
				if (DFS(i, 0))
					ans++;
		}
		cout << "Case " << cnt++ << ": ";
		if (ans > 1)
			cout << "A forest of " << ans << " trees.\n";
		else if (ans == 1)
			cout << "There is one tree.\n";
		else if (ans == 0)
			cout << "No trees.\n";
	}
}