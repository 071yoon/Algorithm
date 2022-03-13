#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test_c, cnt, num;
	cin >> test_c;
	while(test_c--){
		cin >> cnt;
		vector <int> vec;
		for(int i = 0; i < cnt; i++){
			cin >> num;
			vec.push_back(num);
		}
		int max_val = -1;
		long long ret = 0;
		for(int i = cnt - 1; i >= 0; i--){
			max_val = max(vec[i], max_val);
			ret += max_val - vec[i];
		}
		cout << ret << "\n";
	}
}