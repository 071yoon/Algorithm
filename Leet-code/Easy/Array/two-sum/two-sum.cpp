#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> m;
        vector <int> ret;
        for(int i = 0; i < nums.size(); i++){
            int finding_sum = target - nums[i];
            if (m.count(finding_sum)){
                ret.push_back(m[finding_sum]);
                ret.push_back(i);
                return (ret);
            }
            m.insert(make_pair(nums[i], i));
        }
        return (ret);
    }
};

int main(){
    Solution sol;
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(3);


    vector<int> ret;
    ret = sol.twoSum(vec, 6);
    for(int i = 0; i < ret.size(); i++){
        cout << ret[i] << " ";
    }

}