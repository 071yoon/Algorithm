#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue <int, vector<int>, greater<int> > que;
	vector <int> inputs;
	int cnt, num;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> num;
		inputs.push_back(num);
		for(int i = 0; i < inputs.size(); i++){
			que.push(inputs[i]);
		}
		vector <int> vec;
		for(int i = 0; i < que.size(); i++){
			vec.push_back(que.top());
			que.pop();
		}
		cout << vec[vec.size() / 2] << "\n";
	}
}