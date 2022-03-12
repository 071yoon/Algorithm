#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#define ll long long
using namespace std;

ll day, like_total, kind, ender = 0;
vector <pair<ll, ll> > beer;

bool cmp(long long &a, long long &b){
	return (a > b);
}
void inputs(){
	ll like, level;
	for(int i = 0; i < kind; i++){
		cin >> like >> level;
		beer.push_back(make_pair(level, like));
		ender = max(ender, level);
	}
}

bool is_okay(int mid){
	vector <ll> tmp;
	ll beer_val = 0;
	for(int i = 0; i < kind; i++){
		if (beer[i].first <= mid){
			tmp.push_back(beer[i].second);
		}
	}
	if (tmp.size() < day) return false;
	sort(tmp.begin(), tmp.end(), cmp);
	for(int i = 0; i < day; i++){
		beer_val += tmp[i];
	}
	if (beer_val >= like_total) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> day >> like_total >> kind;
	inputs();
	ll ret = LLONG_MAX;
	ll start = 1;
	while(start <= ender){
		ll mid = (start + ender) / 2;
		if(is_okay(mid)){
			ret = mid;
			ender = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	if (ret == LLONG_MAX) cout << "-1\n";
	else cout << ret << "\n";
	return (0);
}