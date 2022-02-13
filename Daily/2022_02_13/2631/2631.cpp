#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, num;
	cin >> cnt;
	vector <pair<int, int> > children;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		children.push_back(make_pair(num, 1));
	}
	int ret = 0;
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < i; j++){
			if (children[j].first < children[i].first && children[j].second + 1 > children[i].second){
				children[i].second = children[j].second + 1;
				ret = max(children[i].second, ret);
			}
		}
	}
	cout << cnt - ret << "\n";
}

/*

3 7 5 2 6 1 4
1 3 7 5 2 6 4
1 2 3 7 5 6 4
1 2 3 4 7 5 6
1 2 3 4 5 6 7

Longest Increasing Subsequence

3 7 5 2 6 1 4
1 2 2 1 3 1 2

*/