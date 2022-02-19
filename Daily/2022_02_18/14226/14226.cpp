#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int goal;
bool visited[5000][5000] = {0};

void bfs(){
	queue <pair<pair<int, int>, int> > que;//display, clipboard
	que.push(make_pair(make_pair(1, 0), 0));
	visited[1][0] = 1;
	while(!que.empty()){
		int display = que.front().first.first;
		int clipboard = que.front().first.second;
		int time = que.front().second;
		que.pop();
		if (display == goal){
			cout << time << "\n";
			return ;
		}
		if (display + clipboard <= 2000 && !visited[display + clipboard][clipboard]){
			visited[display + clipboard][clipboard] = 1;
			que.push(make_pair(make_pair(display + clipboard, clipboard), time + 1));
		}
		if (!visited[display][display]){
			visited[display][display] = 1;
			que.push(make_pair(make_pair(display, display), time + 1));
		}
		if (display - 1 >= 0 && !visited[display - 1][clipboard]){
			visited[display - 1][clipboard] = 1;
			que.push(make_pair(make_pair(display - 1, clipboard), time + 1));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> goal;
	bfs();
}