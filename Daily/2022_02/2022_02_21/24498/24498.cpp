#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, ret = 0, num;
	cin >> cnt;
	vector <int> vec;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		ret = max(ret, num);
		vec.push_back(num);
		if (i >= 2){
			ret = max(ret, vec[i - 1] + min(vec[i - 2], vec[i]));
		}
	}
	cout << ret << "\n";
}