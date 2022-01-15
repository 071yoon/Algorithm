#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;

vector <int> arr[101];
bool visited[101] = {0};
int N, M;
queue <pair <int, int> > que;

int BFS(int person, int sum){
	while (!que.empty()){
		int cur_search = que.front().first;
		int cnt = que.front().second;
		que.pop();
		for(int i = 0; i < arr[cur_search].size(); i++){
			if (!visited[arr[cur_search][i]]){
				que.push(make_pair(arr[cur_search][i], cnt + 1));
				visited[arr[cur_search][i]] = 1;
				sum += cnt + 1;
			}
		}
	}
	return (sum);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int num1, num2;
	while(M--){
		cin >> num1 >> num2;
		arr[num1].push_back(num2);
		arr[num2].push_back(num1);
	}
	int relationship = INT_MAX;
	int ret = 1;
	for(int i = 1; i <= N; i++){
		memset(visited, 0, sizeof(visited));
		que.push(make_pair(i, 0));
		visited[i] = 1;
		int now_relationship = BFS(i, 0);
		if (relationship > now_relationship){
			relationship = now_relationship;
			ret = i;
		}
	}
	cout << ret << "\n";
}