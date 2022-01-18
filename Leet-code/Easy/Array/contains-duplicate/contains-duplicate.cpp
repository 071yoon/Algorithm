#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		int sz = nums.size();
		set <int> set;
        for(int i = 0; i < sz; i++){
			if (set.find(nums[i]) == set.end()){
				set.insert(nums[i]);
			}
			else
				return (true);
		}
		return (false);
    }
};

int main(){

}