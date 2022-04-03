#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int N, Q;
string house_no[1001] = {""};
bool visited[1001] = {0};
bool flag = 0;
vector <int> graph[1001];

void print_ans(string ans){
	long long tmp = 0;
	for(int i = 0; i < ans.size(); i++){
		tmp = tmp * 10 + ans[i] - '0';
		if (tmp >= 1000000007) tmp %= 1000000007;
	}
	cout << tmp << "\n";
}

void dfs(int node, string ans, int ender){
	if (node == ender){
		print_ans(ans);
		flag = 1;
		return ;
	}
	for(int i = 0; i < graph[node].size(); i++){
		int next = graph[node][i];
		if (!visited[next]) {
			visited[next] = 1;
			ans += house_no[next];
			dfs(next, ans, ender);
			if (flag) return;
		}
	}
}

void solve(int starter, int ender){
	string tmp = house_no[starter];
	memset(visited, 0, sizeof(visited));
	flag = 0;
	visited[starter] = 1;
	dfs(starter, tmp, ender);
}

void inputs(){
	cin >> N >> Q;
	string tmp;
	for(int i = 1; i <= N; i++){
		cin >> tmp;
		house_no[i] = tmp;
	}
	for(int i = 0; i < N - 1; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 0; i < Q; i++){
		int starter, ender;
		cin >> starter >> ender;
		solve(starter, ender);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
}