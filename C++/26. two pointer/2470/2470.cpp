#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int cmp, ret1, ret2;
vector <int> vec;

void solve(int start, int end){
	if (start >= end)
		return ;
	if (abs(vec[start] + vec[end]) == 0){
		ret1 = vec[start];
		ret2 = vec[end];
		return ;
	}
	else if (abs(vec[start] + vec[end]) < cmp){
		cmp = abs(vec[start] + vec[end]);
		ret1 = vec[start];
		ret2 = vec[end];
	}
	if (vec[start] + vec[end] < 0){
		solve(start + 1, end);
	}
	else if (vec[start] + vec[end] > 0){
		solve(start, end - 1);
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
	sort(vec.begin(), vec.end());
	cmp = 2000000000;
	solve(0, vec.size() - 1);
	cout << ret1 << " " << ret2 << "\n";
}