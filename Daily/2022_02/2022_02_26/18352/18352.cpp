#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K, X;
vector <int> roads[300001];
bool visited [300001] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, K, X, num1, num2;
	cin >> N >> M >> K >> X;
	for(int i = 0; i < M; i++){
		cin >> num1 >> num2;
		roads[num1].push_back(num2);
	}
	queue <pair<int, int> > que; //target, cnt
	visited[X] = 1;
	que.push(make_pair(X, 0));
	vector <int> ret;
	while (!que.empty()){
		int target = que.front().first;
		int cnt = que.front().second;
		que.pop();
		if (cnt >= K){
			ret.push_back(target);
		}
		else{
			for(int i = 0; i < roads[target].size(); i++){
				if (!visited[roads[target][i]]){
					visited[roads[target][i]] = 1;
					que.push(make_pair(roads[target][i], cnt + 1));
				}
			}
		}
	}
	if (ret.size()){
		sort(ret.begin(), ret.end());
		for(int i = 0; i < ret.size(); i++){
			cout << ret[i] << "\n";
		}
		return (0);
	}
	cout << "-1\n";
	return (0);

}