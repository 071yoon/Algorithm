#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		int sz = nums.size();
		for(int i = 0; i < sz - 1; i++){
			if (nums[i] == nums[i + 1]){
				i++;
			}
			else
				return (nums[i]);
		}
		return (nums[sz - 1]);
    }
};

//XOR 풀이로 할 시 더 효율적이다