#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

void solution(){
	int num;
	cin >> num;
	vector <pair<int, int> > vec;
	for(int i = 0; i < num + 2; i++){
		int num1, num2;
		cin >> num1 >> num2;
		vec.push_back(make_pair(num1, num2));
	}
	bool visited[105] = {0};
	visited[0] = 1;
	queue <pair<int, int> > que;
	que.push(make_pair(vec[0].first, vec[0].second));
	while (!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for(int i = 1; i < num + 2; i++){
			if (!visited[i] && abs(x - vec[i].first) + abs(y - vec[i].second) <= 1000){
				visited[i] = 1;
				que.push(make_pair(vec[i].first, vec[i].second));
			}
		}
	}
	if (visited[num + 1])
		cout << "happy\n";
	else
		cout << "sad\n";
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test_case;
	cin >> test_case;
	while(test_case--){
		solution();
	}
}