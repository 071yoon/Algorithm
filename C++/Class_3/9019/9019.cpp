#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

bool visited[10000] = {0};

int BFS(int org, int ans){
	queue <pair<int, string> > que;
	int D, S, L, R, tmp;
	que.push(make_pair(org, ""));
	visited[org] = 1;
	while(1){
		int now_num = que.front().first;
		string orders = que.front().second;
		que.pop();
//		cout << "num : " << now_num << " ans : " << ans << orders << "\n";
		if (now_num == ans){
			cout << orders << "\n";
			return (0);
		}
		D = (now_num * 2) % 10000;
		if (now_num == 0)
			S = 9999;
		else
			S = now_num - 1;
		tmp = now_num / 1000;
		L = (now_num % 1000) * 10 + tmp;
		tmp = now_num % 10;
		R = (tmp * 1000) + (now_num / 10);
//		cout << "D:" << D << " S:" << S << " L:" << L << " R:" << R << orders << "\n";
		if (!visited[D]){
			visited[D] = 1;
			que.push(make_pair(D, orders + "D"));
		}
		if (!visited[S]){
			visited[S] = 1;
			que.push(make_pair(S, orders + "S"));
		}
		if (!visited[L]){
			visited[L] = 1;
			que.push(make_pair(L, orders + "L"));
		}
		if (!visited[R]){
			visited[R] = 1;
			que.push(make_pair(R, orders + "R"));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test_case, org, ans;
	cin >> test_case;
	while(test_case--){
		memset(visited, 0, sizeof(visited));
		cin >> org >> ans;
		BFS(org, ans);
	}
}