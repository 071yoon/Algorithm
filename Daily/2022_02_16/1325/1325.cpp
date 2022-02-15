#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

vector <int> computers[10001];
int cntr[10001] = {0};
bool visited[10001] = {0};
int M, N;

void dfs(int now, int *cnt){
	for(int i = 0; i < computers[now].size(); i++){
		if (!visited[computers[now][i]]){
			visited[computers[now][i]] = 1; 
			*cnt += 1;
			dfs(computers[now][i], cnt);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	int num1, num2;
	for(int i = 0; i < M; i++){
		cin >> num1 >> num2;
		computers[num2].push_back(num1);
	}
	int max_val = 0;
	for(int i = 1; i <= N; i++){
		cntr[i] = 0;
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		dfs(i, &cntr[i]);
//		cout << cntr[i] << "\n";
		max_val = max(max_val, cntr[i]);
	}
	for(int i = 1; i <= N; i++){
		if (cntr[i] == max_val){
			cout << i << " ";
		}
	}
}