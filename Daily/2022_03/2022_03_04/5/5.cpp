#include <unordered_map>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int sz;
	unordered_map <int, int> ump;
	cin >> sz;
	for(int i = 0; i < sz * sz; i++){
		int val, cnt, time;
		cin >> val >> cnt;
		for(int j = 0; j < cnt; j++){
			cin >> time;
			if (ump.count(time) == 0){
				ump[time] = val;
			}
			else{
				if (ump[time] < val){
					ump[time] = val;
				}
			}
		}
	}
	int ans = 0;
	for(auto it = ump.begin(); it != ump.end(); it++){
		ans += it->second;
	}
	cout << ans << "\n";
}