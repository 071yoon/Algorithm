#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		vector <int> ans;
        int sz = digits.size();
		int index = 1;
		while (sz != index && digits[sz - index] == 9){
			index++;
		}
		if (sz == index && digits[0] == 9){
			ans.push_back(1);
			for(int i = 0; i < sz; i++)
				ans.push_back(0);
		}
		else{
			index = sz - index;
			for(int i = 0; i < index; i++)
				ans.push_back(digits[i]);
			ans.push_back(digits[index] + 1);
			for(int i = index + 1; i < sz; i++){
				ans.push_back(0);
			}
		}
		return (ans);
    }
};