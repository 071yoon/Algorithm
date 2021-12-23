#include <deque>
#include <iostream>
#include <string>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt, num;
	string text;
	deque <int> deq;
	cin >> cnt;
	for (int loop = 0; loop < cnt; loop++){
		cin >> text;
		if (text == "push_front"){
			cin >> num;
			deq.push_front(num);
		}
		else if (text == "push_back"){
			cin >> num;
			deq.push_back(num);
		}
		else if (text == "pop_front"){
			if (deq.empty())
				cout << "-1\n";
			else{
				cout << deq.front() << "\n";
				deq.pop_front();
			}
		}
		else if (text == "pop_back"){
			if (deq.empty())
				cout << "-1\n";
			else{
				cout << deq.back() << "\n";
				deq.pop_back();
			}			
		}
		else if (text == "size"){
			cout << deq.size() << "\n";
		}
		else if (text == "empty"){
			if (deq.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (text == "front"){
			if (deq.empty())
				cout << "-1\n";
			else
				cout << deq.front() << "\n";
		}
		else if (text == "back"){
			if (deq.empty())
				cout << "-1\n";
			else
				cout << deq.back() << "\n";
		}
	}
}