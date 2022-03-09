#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long x, cnt, num;
	while(cin >> x >> cnt){
	x *= 10000000;
		vector<long long> vec;
		for (int i = 0; i < cnt; i++) {
			cin >> num;
			vec.push_back(num);
		}
		sort(vec.begin(), vec.end());
		int low = 0, high = vec.size() - 1;
		bool flag = false;
		while (low < high) {
			int sum = vec[low] + vec[high];
			if (sum == x) {
				flag = true;
				break;
			}
			if (sum < x) {
				low++;
			}
			else { 
				high--;
			}
		}
		if (flag)
			cout << "yes " << vec[low] << " " << +vec[high] << endl;
		else
			cout << "danger" << endl;
	}
}