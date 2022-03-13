#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, tmp;
	vector <int> nums;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> tmp;
		nums.push_back(tmp);
	}
	sort(nums.begin(), nums.end());
	vector <int> sum;
	for(int i = 0; i < cnt; i++){
		for(int j = i; j < cnt; j++){
			sum.push_back(nums[i] + nums[j]);
		}
	}
	sort(sum.begin(), sum.end());
	int result = 0;
	for(int i = 0; i < cnt; i++){
		for(int j = i + 1; j < cnt; j++){
			if (binary_search(sum.begin(), sum.end(), nums[j] - nums[i])){
				result = max(result, nums[j]);
			}
		}
	}
	cout << result << "\n";

}