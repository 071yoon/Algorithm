#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int sz, score, times, time;
	unordered_map <int, int> ump;
	cin >> sz;
	for(int i = 0; i < sz * sz; i++){
		cin >> score >> times;
		for(int j = 0; j < times; j++){
			cin >> time;
			if (ump.count(time)) ump[time] = max(ump[time], score);
			else ump[time] = score;
		}
	}
	int ret = 0;
	for(auto it = ump.begin(); it != ump.end(); it++){
		ret += it->second;
	}
	cout << ret << "\n";
}
//11mins 09sec