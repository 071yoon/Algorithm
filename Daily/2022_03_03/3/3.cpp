#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, eat, me, num;
	vector <int> vec;
	cin >> cnt >> eat >> me;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		vec.push_back(num);
	}
	int min_len = 987654321;
	for(int i = 0; i <= cnt - eat; i++){
		int low = vec[i];
		int hi = vec[i + eat - 1];
		int tmp = max(abs(low - hi), max(abs(me - low), abs(me - hi)));
		min_len = min(tmp, min_len);
	}
	cout << min_len << "\n";

}
//11mins 35sec