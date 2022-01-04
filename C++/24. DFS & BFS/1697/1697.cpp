#include <iostream>
#include <queue>

using namespace std;
queue <pair <int, int> > sb;
int visit[100001] = {0};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int subin, sister;
	cin >> subin >> sister;
	sb.push(make_pair(subin, 0));
	visit[subin] = 1;
	int ret;
	while (!sb.empty()){
		int now = sb.front().first;
		int time = sb.front().second;
		sb.pop();
		if (now == sister){
			ret = time;
			break;
		}
		if (now + 1 < 100001 && !visit[now + 1]){
			sb.push(make_pair(now + 1, time + 1));
			visit[now + 1] = 1;
		}
		if (now - 1 >= 0 && !visit[now - 1]){
			sb.push(make_pair(now - 1, time + 1));
			visit[now - 1] = 1;
		}
		if (2 * now < 100001 && !visit[2 * now]){
			sb.push(make_pair(2 * now, time + 1));
			visit[2 * now] = 1;
		}
	}
	cout << ret << "\n";

}