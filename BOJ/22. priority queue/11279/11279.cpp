#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue <unsigned long long> que;
	int cnt;
	unsigned long long num;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		if (num == 0){
			if (que.empty())
				cout << "0\n";
			else{
				cout << que.top() << "\n";
				que.pop();
			}
		}
		else{
			que.push(num);
		}
	}
}
