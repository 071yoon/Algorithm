#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int min_val = INT_MAX, cnt, num;
	cin >> cnt;
	vector <int> vec;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		vec.push_back(num);
	}
	int start = 0;
	int ender = vec.size() - 1;
	int ret1, ret2;
	while (start < ender){
		int val = vec[ender] + vec[start];
		if (val == 0){
			ret1 = vec[start];
			ret2 = vec[ender];
			break ;
		}
		if (abs(val) < min_val){
			ret1 = vec[start];
			ret2 = vec[ender];
			min_val = abs(val);
		}
		if (val > 0){
			ender--;
		}
		else{
			start++;
		}
	}
	cout << ret1 << " " << ret2 << "\n";
}