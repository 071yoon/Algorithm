#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans_map[101][101] = {0};
vector <int> graph[101];

void DFS(int num, int next){
	for(int i = 0; i < graph[next].size(); i++){
		if (!ans_map[num][graph[next][i]]){
			ans_map[num][graph[next][i]] = 1;
			DFS(num, graph[next][i]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt, num;
	cin >> cnt;
	for(int i = 1; i <= cnt; i++){
		for(int j = 1; j <= cnt; j++){
			cin >> num;
			if (num){
				graph[i].push_back(j);
			}
		}
	}
	for(int i = 1; i <= cnt; i++){
		for(int j = 0; j < graph[i].size(); j++){
			ans_map[i][graph[i][j]] = 1;
			DFS(i, graph[i][j]);
		}
	}
	for(int i = 1; i <= cnt; i++){
		for(int j = 1; j <= cnt; j++)
			cout << ans_map[i][j] << " ";
		cout << "\n";
	}
}