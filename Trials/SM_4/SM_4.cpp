#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <int> plates;
bool visited[100] = {0};

int dfs(int node, int cnt){
	if (visited[node])
		return (cnt);
	else{
		visited[node] = 1;
		return(dfs(node + plates[node], cnt + 1));
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num, tmp;
	cin >> num;
	for(int i = 0; i < num; i++){
		cin >> tmp;
		plates.push_back(tmp);
	}
	int ret = 0;
	ret = max(ret, dfs(0, 1));
	memset(visited, 0, sizeof(visited));
	ret = max(ret, dfs(1, 1));
	memset(visited, 0, sizeof(visited));
	ret = max(ret, dfs(2, 1));
	cout << ret << "\n";
}