#include <iostream>
#include <queue>
#include <vector>
using namespace std;
	
bool visited[1000000] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int max_el, first_fl, desti_fl, up, down;
	cin >> max_el >> first_fl >> desti_fl >> up >> down;
	queue <pair<int, int> > que; //floor & cnt
	visited[first_fl] = 1;
	que.push(make_pair(first_fl, 0));
	while(!que.empty()){
		int curr_fl = que.front().first;
		int cnt = que.front().second;
		que.pop();
		if (curr_fl == desti_fl){
			cout << cnt << "\n";
			return (0);
		}
		int up_fl = curr_fl + up;
		int down_fl = curr_fl - down;
		if (up_fl <= max_el && !visited[up_fl]){
			visited[up_fl] = 1;
			que.push(make_pair(up_fl, cnt + 1));
		}
		if (down_fl > 0 && !visited[down_fl]){
			visited[down_fl] = 1;
			que.push(make_pair(down_fl, cnt + 1));
		}
	}
	cout << "use the stairs\n";
}