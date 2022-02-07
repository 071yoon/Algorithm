#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector <int> vec[101];
	int visited[101] = {0};
	int people, find1, find2, cnt, num1, num2;
	cin >> people >> find1 >> find2 >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num1 >> num2;
		vec[num1].push_back(num2);
		vec[num2].push_back(num1);
	}
	queue <int> que;
	que.push(find1);
	while(!que.empty()){
		int now = que.front();
		if (now == find2){
			cout << visited[now] << "\n";
			return (0) ;
		}
		que.pop();
		for(int i = 0; i < vec[now].size(); i++){
			if (visited[vec[now][i]] == 0){
				visited[vec[now][i]] = visited[now] + 1;
				que.push(vec[now][i]);
			}
		}
	}
	cout << "-1\n";
}