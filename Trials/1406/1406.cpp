#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;
	int cnt;
	list <char> lst(str.begin(), str.end());
	cin >> cnt;
	auto ptr = lst.end();
	for(int i = 0; i < cnt; i++){
		char c1, c2;
		cin >> c1;
		if (c1 == 'L'){
			if (ptr != lst.begin())
				ptr--;
		}
		else if (c1 == 'D'){
			if (ptr != lst.end())
				ptr++;
		}
		else if (c1 == 'B'){
			if (ptr != lst.begin()){
				auto ptr2 = ptr;
				ptr2--;
				lst.erase(ptr2);
			}
		}
		else{
			cin >> c2;
			lst.insert(ptr, c2);
		}
	}
	for(auto it = lst.begin(); it != lst.end(); it++){
		cout << *it;
	}
	cout << "\n";
}
