#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int op[4] = {0};
int cnt, num;
int max_val = INT_MIN, min_val = INT_MAX;
vector <int> nums;

void back_tracking(int val, int cntr){
	if (cntr == cnt - 1){
		max_val = max(max_val, val);
		min_val = min(min_val, val);
		return ;
	}
	for(int i = 0; i < 4; i++){
		if (op[i]){
			op[i]--;
			if (i == 0){
				back_tracking(val + nums[cntr + 1], cntr + 1);
			}
			else if (i == 1){
				back_tracking(val - nums[cntr + 1], cntr + 1);
			}
			else if (i == 2){
				back_tracking(val * nums[cntr + 1], cntr + 1);
			}
			else{
				back_tracking(val / nums[cntr + 1], cntr + 1);
			}
			op[i]++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> cnt;

	for(int i = 0; i < cnt; i++){
		cin >> num;
		nums.push_back(num);
	}
	for(int i = 0; i < 4; i++)
		cin >> op[i];
	back_tracking(nums[0], 0);
	cout << max_val << "\n" << min_val << "\n";
}