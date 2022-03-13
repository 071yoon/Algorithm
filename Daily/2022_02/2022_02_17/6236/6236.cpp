#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int days, times, money, max_val = 0;
	vector <int> vec;
	cin >> days >> times;
	for(int i = 0; i < days; i++){
		cin >> money;
		vec.push_back(money);
		max_val = max(max_val, money);
	}
	int start = max_val;
	int ender = 987654321;
	int ret = 987654321;
	while(start <= ender){
		int mid = (start + ender) / 2;
		int curr = 0;
		int cnt = 0;
		for(int i = 0; i < days; i++){
			if (curr >= vec[i]){
				curr -= vec[i];
			}
			else{
				cnt++;
				curr = mid;
				curr -= vec[i];
			}
		}
		if (cnt <= times){
			ret = min(ret, mid);
			ender = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	cout << ret << "\n";

}