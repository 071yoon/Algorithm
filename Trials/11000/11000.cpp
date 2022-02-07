#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num1, num2;
	multiset <int> s;
	vector <pair<int, int> > vec;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num1 >> num2;
		vec.push_back(make_pair(num1, num2));
	}
	sort(vec.begin(), vec.end());
	s.insert(vec[0].second);

	for(int i = 1; i < cnt; i++){
		/*
		cout << "[" << i << "]" << "\n";
		for(auto it = s.begin(); it != s.end(); it++)
			cout << *it << " ";
		cout << "\n";*/
		if (*s.begin() <= vec[i].first){
			s.erase(s.begin());
			s.insert(vec[i].second);
		}
		else{
			s.insert(vec[i].second);
		}
	}
	cout << s.size() << "\n";
}