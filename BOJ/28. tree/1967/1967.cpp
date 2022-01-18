#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector <pair <int, int> > arr[100001];

int visited[100001];
int max_val = 0;
int max_idx = 0;
int final_sum = 0;

void DFS(int node, int sum){
	visited[node] = true;
	if (max_val < sum){
		max_val = sum;
		max_idx = node;
	}
	for(int i = 0; i < arr[node].size(); i++){
		int next = arr[node][i].first;
		if (!visited[next]){
			DFS(next, sum + arr[node][i].second);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int cnt, num, line, value;
	cin >> cnt;
	for(int i = 1; i < cnt; i++){
		cin >> num;
		cin >> line;
		cin >> value;
		arr[num].push_back(make_pair(line, value));
		arr[line].push_back(make_pair(num, value));
	}
	DFS(1, 0);
	memset(visited, 0, sizeof(visited));
	DFS(max_idx, 0);
	cout << max_val << "\n";
}