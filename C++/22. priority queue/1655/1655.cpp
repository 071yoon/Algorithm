#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue <int> max_que;
	priority_queue <int, vector <int>, greater <int> > min_que;


	int cnt, num;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> num;
		if (max_que.size() == min_que.size()){
			max_que.push(num);
		}
		else if (max_que.size() > min_que.size()){
			min_que.push(num);
		}
		if ((!max_que.empty() && !min_que.empty()) && min_que.top() < max_que.top()){
			int max_tmp = max_que.top();
			int min_tmp = min_que.top();
			max_que.pop();
			min_que.pop();
			max_que.push(min_tmp);
			min_que.push(max_tmp);
		}
		cout << max_que.top() << "\n";
	}
	
}