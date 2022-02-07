#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int target, cnt, num;
	vector <int> vec;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		vec.push_back(num);
	}
	target = vec[vec.size() - 1];
	int ret = 0;
	for(int i = vec.size() - 2; i >= 0; i--){
		if (vec[i] >= target){
			target -= 1;
			ret += (vec[i] - target);
		}
		else
			target = vec[i];
	}
	cout << ret << "\n";
}