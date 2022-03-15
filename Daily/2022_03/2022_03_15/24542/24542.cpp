#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> people[200001];
bool visited[200001] = {0};
long long answer;
int N, M;

void inputs(){
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int from, to;
		cin >> from >> to;
		people[from - 1].push_back(to - 1);
		people[to - 1].push_back(from - 1);
	}
}

void bfs(){
	for (int i = 0; i < N; i++){
		if (!visited[i]){
			queue<int> que;
			que.push(i);
			visited[i] = 1;
			long long tmp = 0;
			while (!que.empty()){
				int curr = que.front();
				que.pop();
				tmp++;
				for (int j = 0; j < people[curr].size(); j++){
					int next = people[curr][j];
					if (!visited[next]){
						visited[next] = 1;
						que.push(next);
					}
				}
			}
			answer = (answer * tmp) % 1000000007;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	inputs();
	answer = 1;
	bfs();
	cout << answer << "\n";
}