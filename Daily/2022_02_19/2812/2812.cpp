#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, del;
	string nums;
	cin >> cnt >> del >> nums;
	vector <char> dq;
	dq.push_back(nums[0]);
	for(int i = 1; i < cnt; i++){
		while(!dq.empty() && del && dq[dq.size() - 1] < nums[i]){
			del--;
			dq.pop_back();
		}
		dq.push_back(nums[i]);
	}
	while(del){
		dq.pop_back();
		del--;
	}
	for(int i = 0; i < dq.size(); i++){
		cout << dq[i];
	}
	cout << "\n";
}
//30 mins 30sec