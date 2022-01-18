#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		int sz = nums.size();
        k = (sz - k) % sz;
		if (k < 0)
			k = sz + k;
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
		reverse(nums.begin(), nums.end());
    }
};

int main(){
	vector <int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);

	Solution sol;
	sol.rotate(nums, 3);
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
}