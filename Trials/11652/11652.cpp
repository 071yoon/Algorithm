#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

bool compare(pair<long long, int> a, pair<long long, int> b){
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	unordered_map <long long, int> m;
	int cnt;
	cin >> cnt;
	long long num;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		m[num]++;
	}
	vector <pair<long long, int> > vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), compare);
	printf("%lld", vec[0].first);
}