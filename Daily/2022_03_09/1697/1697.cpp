#include <iostream>
#include <queue>
using namespace std;

bool visited[100001] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int subin, sis;
	cin >> subin >> sis;
	visited[subin] = 1;
	queue <pair<int, int> > que;
	que.push(make_pair(subin, 0));
	while(!que.empty()){
		int now = que.front().first;
		int tm = que.front().second;
		if (now == sis){
			cout << tm << "\n";
			return (0);
		}
		que.pop();
		if (now + 1 <= 100000 && !visited[now + 1]){
			visited[now + 1] = 1;
			que.push(make_pair(now + 1, tm + 1));
		}
		if (now - 1 >= 0 && !visited[now - 1]){
			visited[now - 1] = 1;
			que.push(make_pair(now - 1, tm + 1));
		}
		if (now * 2 <= 100000 && !visited[2 * now]){
			visited[2 * now] = 1;
			que.push(make_pair(2 * now, tm + 1));
		}
	}
}