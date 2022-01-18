#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	deque <int> dq;
	int cnt, num;
	string op;
	cin >> cnt;
	while(cnt--){
		cin >> op;
		if(op == "push"){
			cin >> num;
			dq.push_back(num);
		}
		else if (op == "pop"){
			if(dq.empty()){
				cout << "-1\n";
			}
			else{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (op == "size"){
			cout << dq.size() << "\n";
		}
		else if (op == "empty"){
			if (dq.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (op == "front"){
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.front() << "\n";
		}
		else if (op == "back"){
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.back() << "\n";
		}
	}
}