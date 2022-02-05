#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt, sum, num;
int ret = 0;
vector <int> nums;
int summer = 0;

void back_tracking(int cntr, int cur, int index){
	if (cur == cntr){
		if (summer == sum)
			ret++;
		return ;
	}
	for(int i = index; i < nums.size(); i++){
		summer += nums[i];
		back_tracking(cntr, cur + 1, i + 1);
		summer -= nums[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> cnt >> sum;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		nums.push_back(num);
	}
	for(int i = 1; i <= nums.size(); i++){
		back_tracking(i, 0, 0);
	}
	cout << ret << "\n";
}