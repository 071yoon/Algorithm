#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int parent[MAX];
bool visited[MAX];
vector <int> v[MAX];

void dfs(int node){
	visited[node] = true;
	for(int i = 0; i < v[node].size(); i++){
		int next = v[node][i];
		if (!visited[next]){
			parent[next] = node;
			dfs(next);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int lines;
	cin >> lines;
	for(int i = 1; i < lines; i++){
		int node1, node2;
		cin >> node1 >> node2;
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}
	dfs(1);
	for(int i = 2; i <= lines; i++)
		cout << parent[i] << "\n";
}
