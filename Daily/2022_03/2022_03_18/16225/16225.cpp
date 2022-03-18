#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;
vector <pair<int, int> > nums;

bool cmp(pair<int, int> &a, pair<int, int> &b){
	return a.second < b.second;
}

void inputs(){
	cin >> cnt;
	int num;
	vector <int> num1; vector <int> num2;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		num1.push_back(num);
	}
	for(int i = 0; i < cnt; i++){
		cin >> num;
		num2.push_back(num);
	}
	for(int i = 0; i < cnt; i++){
		nums.push_back(make_pair(num1[i], num2[i]));
	}
	sort(nums.begin(), nums.end(), cmp);
}

void solve(){
	long long ans = 0;
	ans += nums[0].first;
	priority_queue <int> pq;
	for(int i = 1; i < cnt - 1; i += 2){
		pq.push(nums[i].first);
		pq.push(nums[i + 1].first);
		ans += pq.top();
		pq.pop();
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solve();
}