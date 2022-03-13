#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int people[501] = {0};
bool visited[501] = {0};
vector <int> relation[501];
int ret = 0;

void solve(){
	queue <pair<int, int> > que;
	que.push(make_pair(1, 0));
	visited[1] = 1;
	while(!que.empty()){
		int cur = que.front().first;
		int cnt = que.front().second;
		que.pop();
		if (cnt >= 1 && cnt <= 2){
			ret++;
		}
		for(int i = 0; i < relation[cur].size(); i++){
			int next = relation[cur][i];
			if (!visited[next] && cnt <= 1){
				visited[next] = 1;
				que.push(make_pair(next, cnt + 1));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, relation_cnt;
	cin >> cnt;
	for(int i = 1; i <= cnt; i++){
		people[i] = i;
	}
	cin >> relation_cnt;
	for(int i = 0; i < relation_cnt; i++){
		int num1, num2;
		cin >> num1 >> num2;
		relation[num1].push_back(num2);
		relation[num2].push_back(num1);
	}
	solve();
	cout << ret << "\n";
}
//9 mins 18 sec