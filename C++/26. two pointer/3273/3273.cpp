#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> vec;
int ret, x;
void solve(int start, int end){
	if (start >= end)
		return ;
	else if (vec[start] + vec[end] == x){
		ret++;
		solve(start + 1, end - 1);
	}
	else if (vec[start] + vec[end] > x){
		solve(start, end - 1);
	}
	else if (vec[start] + vec[end] < x){
		solve(start + 1, end);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt, num;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		vec.push_back(num);
	}
	cin >> x;
	sort(vec.begin(), vec.end());
	ret = 0;
	solve(0, vec.size() - 1);
	cout << ret;
}