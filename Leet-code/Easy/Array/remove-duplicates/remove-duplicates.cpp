#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.size() == 0)
		return (0);
    for(int i = 0; i < nums.size() - 1; i++){
		if (nums[i] == nums[i + 1]){
			nums.erase(nums.begin() + i);
			i--;
		}
	}
	return (nums.size());
}

int main(){
	vector <int> nums;
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(4);
	cout << removeDuplicates(nums) << "\n";
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
}