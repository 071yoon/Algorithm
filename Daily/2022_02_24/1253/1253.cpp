#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	unordered_map <int, int> ump;
	int cnt, num;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		ump[num] = 1;
	}
	int ret = 0;
	for(auto i = ump.begin(); i != ump.end(); i++){
		for(auto j = ump.begin(); j != ump.end(); j++){
			int num1 = i->first;
			int num2 = j->first;
			cout << num1 << ":" << num2 << "\n";
			int mi = num1 - num2;
			cout << mi << "\n";
			if (i == j){
				continue;
			}
		//	cout << ump[mi] << "\n";
			/*
			if (ump[num1 - num2] >= 0){
				cout << num1 - num2 << "\n";
				ret++;
				break ;
			}*/
		}
	}
	cout << ret << "\n";
}