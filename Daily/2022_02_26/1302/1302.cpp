#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
	if (a.second == b.second){
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	unordered_map <string, int> ump;
	int cnt; string str;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> str;
		ump[str]++;
	}
	//vector <string, int> vec;
	vector <pair<string, int> > vec(ump.begin(), ump.end());
	sort(vec.begin(), vec.end(), compare);
	cout << vec[0].first << "\n";
}