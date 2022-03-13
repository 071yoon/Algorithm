#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector <int> vec;
	int cnt, num;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	int max_num = 0;
	do{
		int ret = 0;
		for(int i = 0; i < cnt - 1; i++){
			ret += abs(vec[i] - vec[i + 1]);
		}
		max_num = max(ret, max_num);
	}while(next_permutation(vec.begin(), vec.end()));
	cout << max_num << "\n";
}

/*

1 4 8 10 15 20 [13] [45]
19 + 11 + 2

*/