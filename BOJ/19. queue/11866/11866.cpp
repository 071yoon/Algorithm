#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt, num;

	cin >> cnt >> num;
	queue <int> que;
	vector <int> v;
	for (int i = 0; i < cnt; i++){
		que.push(i + 1);
	}
	for (int loop = 0; loop < cnt; loop++){
		for (int i = 0; i < num - 1; i++){
			que.push(que.front());
			que.pop();
		}
		v.push_back(que.front());
		que.pop();
	}
	cout << "<";
	for (int i = 0; i < cnt; i++){
		cout << v[i];
		if (i != cnt - 1)
			cout << ", ";
	}
	cout << ">";

}