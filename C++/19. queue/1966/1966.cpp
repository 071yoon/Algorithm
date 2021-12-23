//1 2 3 4 5 6
//1 1 9 1 1 1

//0 1 2 3
//1 2 3 4

#include <queue>
#include <iostream>
#include <utility>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt;
	int num, finder;
	int value, ret;

	cin >> cnt;
	for (int loop = 0; loop < cnt; loop++){
		priority_queue<int> pri;
		queue <pair<int, int> > que;
		ret = 1;
		cin >> num >> finder;
		for(int i = 0; i < num; i++){
			cin >> value;
			que.push(make_pair(i, value));
			pri.push(value);
		}
		while (1){
			if (que.front().second == pri.top()){
				if (que.front().first == finder){
					cout << ret << "\n";
					break;
				}
				else{
					que.pop();
					pri.pop();
					ret += 1;
				}
			}
			else{
				que.push(que.front());
				que.pop();
			}
		}
	}
}