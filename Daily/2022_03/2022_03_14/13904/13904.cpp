#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cnt, ans;
vector <pair<int, int> > hw; //importance and day
int score[1001] = {0};

bool cmp(pair<int, int> &a, pair<int, int> &b){
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}

void inputs(){
	cin >> cnt;
	int importance, day;
	for(int i = 0; i < cnt; i++){
		cin >> day >> importance;
		hw.push_back(make_pair(importance, day));
	}
	sort(hw.begin(), hw.end(), cmp);
}

void solve(){
	for(int i = 0; i < cnt; i++){
		int cur = hw[i].second;
		while(1){
			if (score[cur] == 0){
				score[cur] = hw[i].first;
				break ;
			}
			else{
				cur--;
				if (cur == 0) break;
			}
		}
	}
	ans = 0;
	for(int i = 1; i <= 1000; i++){
		ans += score[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solve();
	cout << ans << "\n";
}