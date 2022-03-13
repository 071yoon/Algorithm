#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cur, more, max_len;
vector <int> lens;

void inputs(){
	int tmp;
	cin >> cur >> more >> max_len;
	lens.push_back(0); lens.push_back(max_len);
	for(int i = 0; i < cur; i++){
		cin >> tmp;
		lens.push_back(tmp);
	}
	sort(lens.begin(), lens.end());
}

void solve(){
	int starter = 1; int ender = max_len; int ret = 987654321;
	while (starter <= ender){
		int mid = (starter + ender) / 2;
		int cnt = 0;
		for(int i = 0; i < lens.size() - 1; i++){
			int gijun = lens[i + 1] - lens[i];
			int tmp = gijun / mid;
			if (tmp && (gijun % mid == 0)) tmp--;
			cnt += tmp;
		}
		if (cnt <= more){
			ret = mid;
			ender = mid - 1;
		}
		else{
			starter = mid + 1;
		}
	}
	cout << ret << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solve();
}