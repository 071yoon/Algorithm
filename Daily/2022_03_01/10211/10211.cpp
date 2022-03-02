#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt1, cnt2, num;
	cin >> cnt1;
	while(cnt1--){
		cin >> cnt2;
		cin >> num;
		int ret = num;
		int max_val = num;
		for(int i = 1; i < cnt2; i++){
			cin >> num;
			if (num > num + ret){
				ret = num;
			}
			else{
				ret = num + ret;
			}
			max_val = max(max_val, ret);
		}
		cout << max_val << "\n";
	}
}
/*

2 1 -2 3 -5
2 3 1  4 -1

*/